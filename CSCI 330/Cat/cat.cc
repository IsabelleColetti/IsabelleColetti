/************************************************
*
* CSCI 330 Assignment 3
* Isabelle Coletti (z1900409)
* Section 1
*
************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <cstring>

#define BUFFER_SIZE 4096

using namespace std;

int main(int argc, char *argv[])
{
	int fd;
	char buffer[4096];
	ssize_t numRead;

	//check if the number of arguments is more than 1
	if(argc > 1)
	{
		//go through every argument and open, read, and write it
		for(int i = 1; i < argc; i++)
		{
			//check if the argument is - and if so, read from standard input
			if(strcmp(argv[i], "-") == 0)
			{
				fd = 0;
				numRead = read(0, buffer, BUFFER_SIZE);
				buffer[numRead] = 0;
				cout << buffer;
			}

			//if the argument is a file name, open it
			else
			{
				fd = open(argv[i], O_RDONLY);
				
				if(fd == -1)
				{
					perror("open");
					return 2;
				}
		
				//read the file once
				numRead = read(fd, buffer, BUFFER_SIZE);
				if(numRead == -1)
				{
					perror("read");
					return 3;
				}

				//continue reading and writing until end of file has been reached
				while(numRead > 0)
				{
					buffer[numRead] = 0;
	
					write(1, buffer, numRead);
		
					numRead = read(fd, buffer, BUFFER_SIZE);
				}

				//close file
				close(fd);
			}
		}
	}
	else
	{
		//print error if there are not more than 2 arguments
		cerr << "Error: No argument" << endl;
		return 1;
	}

	return 0;
}
