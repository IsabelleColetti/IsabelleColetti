/*****************************************************
*
* CSCI 330 Section 1
* Assignment 9
* Created by Isabelle Coletti (z1900409)
* tcp-z1900409.cc
*
*****************************************************/
#include <dirent.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main(int argc, char* argv[])
{
  char buffer[4096] = {};
  int sock, newSock;
  socklen_t serverlen, clientlen;
  ssize_t received;
  struct sockaddr_in server_addr;      //structure for address of server
 	struct sockaddr_in client_addr;      //structure for address of client

	//make sure all 3 arguments are present
	if(argc != 3)
	{
		//if not, print error message and exit
		cerr << "Error: 2 command line arguments necessary. 1) Port number, 2) Path to a directory.\n";
		exit(EXIT_FAILURE);
	}

	//create TCP socket
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		//if socket fails, print message and exit
		perror("Failed to create socket");
		exit(EXIT_FAILURE);
	}
	
	//create address structures
	memset(&server_addr, 0, sizeof(server_addr));			//clear struct
	server_addr.sin_family = AF_INET;									//internet/IP
	server_addr.sin_addr.s_addr = INADDR_ANY;					//any IP address
	server_addr.sin_port = htons(atoi(argv[1]));			//server port

	//bind the socket
	serverlen = sizeof(server_addr);
	if(bind(sock, (struct sockaddr *) &server_addr, serverlen) < 0)
	{
		//if bind fails, print message and exit
		perror("Failed to bind server socket");
		exit(EXIT_FAILURE);
	}

	//listen on the port
	if(listen(sock, 64) < 0)
	{
		//if listen fails, print message and exit
		perror("listen failed");
		exit(EXIT_FAILURE);
	}

	clientlen = sizeof(client_addr);
	//loop while(true) and fork
	while(true)
	{
		//accept the connection from the client
		newSock = accept(sock, (struct sockaddr *)&client_addr, &clientlen);
		if(newSock < 0)
		{
			//if accept fails, print message and exit
			perror("accept failed");
			exit(EXIT_FAILURE);
		}

		if(fork())			//parent
			close(newSock);
		else						//child
		{
			//read a message from the client
			if((received = read(newSock, buffer, sizeof(buffer))) < 0)
			{
				//if read fails, print message and exit
				perror("receive failed");
				exit(EXIT_FAILURE);
			}
		
			string pathname, path;
			char* unused;

			//read the GET part of the request into a storage variable
			unused = strtok(buffer, " ");
			//read the actual path into a variable
			path = strtok(NULL, "\r\n ");
			string str = "..";

			//check to see if the path contains ".."
			if(path.find(str) != string::npos)
			{
				//if so, send appropriate error message
				char error[4096] = {};
				strcpy(error, "Error: path may not contain \"..\"\n");
				//send the message
				write(newSock, error, sizeof(error));
				//exit
				exit(EXIT_FAILURE);
			}

			//check to see if the path begins with "/"
			if(path[0] != '/')
			{
				//if so, send appropriate error message
				char error[4096] = {};
				strcpy(error, "Error: path must begin with \'/\'\n");
				//send the message
				write(newSock, error, sizeof(error));
				//exit
				exit(EXIT_FAILURE);
			}

			//create actual pathname with root directory
			pathname += argv[2];
			pathname += path;

			//create stat object
			struct stat s;
			//use stat to check if the pathname is valid
			if( stat(pathname.c_str(),&s) == 0 )
			{
				//use bitmask on st_mode to check the types of paths
    		auto mode = (s.st_mode & S_IFMT);

				//check if the pathname is a directory
				if(mode == S_IFDIR)
				{
					//create buffers to use later
					char buf[4096] = {};
					char buff[4096] = {};
					int fd;

					//open the directory
					DIR *dirp = opendir(pathname.c_str());
					//check if open failed
					if(dirp == NULL)
					{
						//dup standard error to write to client
						close(2);
						dup(newSock);
						//if it was not a directory
						if(errno == ENOTDIR)
						{
							//print error message and exit
							cerr << "Error: is not a directory.\n";
							exit(EXIT_FAILURE);
						}
						//if it does not exist
						else if(errno == ENOENT)
						{
							//print error message and exit
							cerr << "Error: directory does not exist.\n";
							exit(EXIT_FAILURE);
						}
						//otherwise
						else
						{
							//print general error message and exit
							cerr << "Error: cannot open directory.\n";
							exit(EXIT_FAILURE);
						}
					}

					//start the buffer out as empty
					strcpy(buf, "");

					//create dirent pointer
					struct dirent* dirEntry;

					//read through the directory until it's empty
					while((dirEntry = readdir(dirp)) != NULL)
					{
						//check if the directory contains a file named "index.html"
						if((strcmp(dirEntry->d_name, "index.html")) == 0)
						{
							int fd;
							//if so, open the file
							if((fd = open("index.html", O_RDONLY)) == -1)
							{
								//if failure, print error ande exit program
								perror("open failed");
								exit(EXIT_FAILURE);
							}
							
							ssize_t numRead;
							//read the file
							if((numRead = read(fd, buff, sizeof(buff))) == -1)
							{
								//if read failed, print error and exit
								perror("read failed");
								exit(EXIT_FAILURE);
							}
	
							//continue until the whole file has been read
							while(numRead > 0)
							{
								//write to the client
								if(write(newSock, buff, sizeof(buff)) < 0)
								{
									//if write failed, print error and exit
									perror("write failed");
									exit(EXIT_FAILURE);
								}

								//continue to read
								numRead = read(fd, buff, sizeof(buff));
							}

							//close the file
							close(fd);
							//close the socket
							close(newSock);
							//exit
							exit(EXIT_SUCCESS);
						}
						//make sure the file name does not start with "."
						else if(dirEntry->d_name[0] != '.')
						{
							//add the file name to the buffer
							strcat(buf, dirEntry->d_name);
							//add a space to the buffer
							strcat(buf, " ");
						}
					}
					//add a new line to the buffer
					strcat(buf, "\n");

					//write the buffer to the client
					if(write(newSock, buf, sizeof(buf)) < 0)
					{
						//if write failed, print error and exit
						perror("write failed");
						exit(EXIT_FAILURE);
					}
					
					//close the directory
					closedir(dirp);
					//close the socket
					close(newSock);
					//exit
					exit(EXIT_SUCCESS);
				}
				//check if the pathname is a file
				else if(mode == S_IFREG)
				{
					//erase the "/" from the pathname
					string filename = path.erase(0, 1);
					int fd;
					char buff[4096] = {};

					//open the file
					if((fd = open(filename.c_str(), O_RDONLY)) == -1)
					{
						//if open fails, print error and exit
						perror("open failed");
						exit(EXIT_FAILURE);
					}

					//check if the file path has a trailing "/"
					if(path.back() == '/')
					{
						//if so, send appropriate error message
						char error[4096] = {};
						strcpy(error, "Error: file path cannot end in \'/\'\n");
						//send the message
						write(newSock, error, sizeof(error));
						//exit
						exit(EXIT_FAILURE);
					}

					ssize_t numRead;
					//read the file
					if((numRead = read(fd, buff, sizeof(buff))) == -1)
					{
						//if read failed, print error and exit
						perror("read failed");
						exit(EXIT_FAILURE);
					}
					//continue to read until whole file has been read
					while(numRead > 0)
					{
						//write the file contents to the client
						if(write(newSock, buff, sizeof(buff)) < 0)
						{
							//if write failed, print error and exit
							perror("write failed");
							exit(EXIT_FAILURE);
						}
						
						//continue reading
						numRead = read(fd, buff, sizeof(buff));
					}
					//close the file
					close(fd);
					//close the socket
					close(newSock);
					//exit
					exit(EXIT_SUCCESS);
				}
				//the pathname was not a file or directory
				else
				{
					//dup standard error
					//print appropriate error message and exit
					cout << "Path is not a directory or does not exist.\n";
					exit(EXIT_FAILURE);
				}
			}
			//stat failed, must be a bad pathname
			else
			{
				//close standard error
				close(2);
				//dup standard error to write to client
				dup(newSock);
				//print error message and exit
				cerr << "Error: " << path << " not found.\n";
				exit(EXIT_FAILURE);
			}
			//close the socket
			close(newSock);
			//exit
			exit(EXIT_SUCCESS);
		}
	}
	//close the socket
	close(sock);
}
