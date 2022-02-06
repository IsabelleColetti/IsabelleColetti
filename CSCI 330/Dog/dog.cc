/*****************************************************
*
* CSCI 330 Section 1
* Assignment 5
* Created by Isabelle Coletti (z1900409)
* dog.cc
*
*****************************************************/
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include "dogheads.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define BUFFER_SIZE 4096

int main(int argc, char* argv[])
{
	
	int fd;
	char buffer[BUFFER_SIZE];
	ssize_t numRead;
	int opt;
	//initialize all got bools to false to begin
	bool gots = false, gotn = false, gotc = false, gotr = false, gotx = false, gotb = false;
	int sarg, narg, carg, rarg;
	//bool representing if there are no command line options
	bool noOpts = false;

	//make sure user entered something other than just ./dog
	if(argc > 1)
	{
		//iterate through each argument and check to see which command line
		//arguments are specified
		while((opt = getopt(argc, argv, "s:n:c:r:xb")) != -1)
		{
			//for each case, change got bool to true if the command line argument is present
			//if the option requires an argument, save that argument as an integer to the arg int
			switch(opt)
			{
				case 's':
					gots = true;
					sarg = atoi(optarg);
					break;

				case 'n':
					gotn = true;
					narg =  atoi(optarg);
					break;

				case 'c':
					gotc = true;
					carg = atoi(optarg);
					break;

				case 'r':
					gotr = true;
					rarg = atoi(optarg);
					break;

				case 'x':
					gotx = true;
					break;

				case 'b':
					gotb = true;
					break;

				//if there is a command line option entered other than those in the getopt string, print appropriate error message and exit
				default:
					perror("Invalid argument.");
					exit(2);
			}
		}

		//check if -r and -c were entered together
		if(gotr and gotc)
		{
			//if so, print appropriate error message and exit
			perror("-r and -c cannot both be specified.");
			exit(3);
		}

		//check if -x and -b were entered together
		if(gotx and gotb)
		{
			//if so, print appropriate error message and exit
			perror("Hexadecimal and Binary notation cannot both be specified.");
			exit(4);
		}

		//check if there are no command line arguments specified
		if(!gots and !gotn and !gotc and !gotr and !gotx and !gotb)
			//set noOpts to true if so
			noOpts = true;

		//check if noOpts is true
		if(noOpts)
		{
			//if so, read and write the file as normal

			//iterate through the files entered
			for(int i = 1; i < argc; i++)
			{
				//if - is entered instead of a file, read from standard input
				if(strcmp(argv[i], "-") == 0)
				{
					fd = 0;
					while((numRead = read(fd, buffer, BUFFER_SIZE)) > 0)
					{
						buffer[numRead] = 0;

						write(1, buffer, numRead);
					}
				}
				//if a file is entered, open it, read it, and write it until end of file
				else
				{
					fd = open(argv[i], O_RDONLY);

					if(fd == -1)
					{
						//if there was an error opening file, print message and exit
						perror("Error opening file.");
						exit(5);
					}

					//read and write the file until there are no more bytes to read or write
					while((numRead = read(fd, buffer, BUFFER_SIZE)) > 0)
					{
						buffer[numRead] = 0;
	
						write(1, buffer, numRead);
					}
					

					if(numRead == -1)
					{
						//if there was an error reading the file, print message and exit
						perror("Error reading file.");
						exit(6);
					}
					//close the file
					close(fd);

				}

			}
			exit(7);
		}

		//check if -s is entered but not -n
		if(gots and !gotn)
		{
			//define a buffer the size of whatever argument was entered after -s
			char bufS[sarg];
			//define a buffer with 8 times the size in case -b is specified
			char bufferEight[sarg * 8];
			//define a buffer with 2 times the size in case -h is specified
			char bufferTwo[sarg * 2];

			//iterate through all of the files entered
			for(int i = optind; i < argc; i++)
			{
				//open the file
				fd = open(argv[i], O_RDONLY);

				//read in all of the bytes in a loop until there aren't any left to read
				while((numRead = read(fd, bufS, sarg)) > 0)
				{
					bufS[numRead] = 0;

					if(numRead == -1)
					{
						//if there was an error reading the file, print message and exit
						perror("Error reading file.");
						exit(8);
					}
					//check if -c was entered
					if(gotc)
					{
						//call cipher
						cipher(bufS, numRead, carg);
						//write the modified buffer
						write(1, bufS, numRead);
					}
					//check if -r was entered
					else if(gotr)
					{
						//call rotator
						rotator(bufS, numRead, rarg);
						//write the modified buffer
						write(1, bufS, numRead);
					}
					//check if -b
					else if(gotb)
					{
						//call binaryform to change the characters to binary notation
						binaryform(bufS, numRead, bufferEight);
						//write the new buffer with binary characters
						write(1, bufferEight, sarg*8);
					}
					//check if -x was entered
					else if(gotx)
					{
						//call hexform to change the characters to hexadecimal notation
						hexform(bufS, numRead, bufferTwo);
						//write the new buffer with hexadecimal characters
						write(1, bufferTwo, sarg*2);
					}
					else
					{
						//if nothing except -s was entered, just write the buffer by reading in and writing the specified number of bytes
						write(1, bufS, numRead);
					}
				}

				write(1, "\n", sizeof("\n"));

				//close the file
				close(fd);
				
			}
			exit(9);

		}
		
		//check if neither -s or -n are specified
		if(!gots and !gotn)
		{
			//declare a buffer with default size * 8 in case -b is entered
			char buffer8[BUFFER_SIZE * 8];
			//declare a buffer with default size * 2 in case -h is entered
			char buffer2[BUFFER_SIZE * 2];

			//iterate through every file entered
			for(int i = optind; i < argc; i++)
			{
				//open the file
				fd = open(argv[i], O_RDONLY);

				//read the bytes until there are no more bytes to be read
				while((numRead = read(fd, buffer, BUFFER_SIZE)) > 0)
				{
					buffer[numRead] = 0;
					
					if(numRead == -1)
					{
						//if there was an error reading the file, print message and exit
						perror("Error reading file.");
						exit(8);
					}
					//check if -c was entered
					if(gotc)
					{
						//call cipher
						cipher(buffer, numRead, carg);
						//write modified buffer
						write(1, buffer, numRead);
					}
					//check if -r was entered
					else if(gotr)
					{
						//call rotator
						rotator(buffer, numRead, rarg);
						//write modified buffer
						write(1, buffer, numRead);
					}
					//check if -b was entered
					else if(gotb)
					{
						//call binaryform to change the characters to binary notation
						binaryform(buffer, numRead, buffer8);
						//write the new buffer with binary characters
						write(1, buffer8, BUFFER_SIZE*8);
					}
					//check if -x was entered
					else if(gotx)
					{
						//call hexform to change the characters to hexadecimal format
						hexform(buffer, numRead, buffer2);
						//write the new buffer with hexadecimal characters
						write(1, buffer2, BUFFER_SIZE*2);
					}
				}

				write(1, "\n", sizeof("\n"));
				
				//close the file
				close(fd);
			}
			exit(10);
		}
		
		//check if only -n is specified
		if(gotn and !gots)
		{
			//declare buffer of size number of bytes specified by -n argument * 8 in case -b is entered
			char buffer8[narg * 8];
			//declare buffer of size number of bytes specified by -n argument * 2 in case -h is entered
			char buffer2[narg * 2];

			//iterate through every file
			for(int i = optind; i < argc; i++)
			{
				//open the file
				fd = open(argv[i], O_RDONLY);

				//set the number of bytes read to the -n integer argument
				numRead = narg;

				//only read in the number of bytes specified by -n integer argument
				read(fd, buffer, numRead);
				buffer[numRead] = 0;
				
				if(numRead == -1)
				{
					//if there was an error reading the file, print message and exit
					perror("Error reading file.");
					exit(11);
				}
					
				//check if -c was entered
				if(gotc)
				{
					//call cipher
					cipher(buffer, numRead, carg);
					//write the modified buffer
					write(1, buffer, numRead);
				}
				//check if -r was entered
				else if(gotr)
				{
					//call rotator
					rotator(buffer, numRead, rarg);
					//write the modified buffer
					write(1, buffer, numRead);
				}
				//check if -b was entered
				else if(gotb)
				{
				//call binaryform to change characters to binary
					binaryform(buffer, numRead, buffer8);
					//write the buffer containing binary characters
					write(1, buffer8, narg*8);
				}
				//check if -x was entered
				else if(gotx)
				{
					//call hexform to change characters to hexadecimal
					hexform(buffer, numRead, buffer2);
					//write the buffer containing hexadecimal characters
					write(1, buffer2, narg*2);
				}
				else
				{
					//if no options other than -n are specified, write normally
					write(1, buffer, numRead);
				}

				write(1, "\n", sizeof("\n"));
				
				//close the file
				close(fd);
			}
			exit(12);
		}
	}
	else
	{
		//print error message if there weren't at least 2 arguments and exit
		perror("No arguments supplied.");
		exit(1);
	}
}
