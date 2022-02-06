/*****************************************************
*
* CSCI 330 Section 1
* Assignment 4
* Created by Isabelle Coletti (z1900409)
*
*****************************************************/

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	//initialize gotc to false before searching for it
	bool gotc = false;

	int fd;
	int opt;

	if(argc > 1)
	{

		//get all command line options

		while((opt = getopt(argc, argv, "c")) != -1)
		{

			switch(opt)
			{
				case 'c': 
					//if -c is found, change gotc to true
					gotc = true;
					break;

				default: 
					//if an invalid option is found, exit and display appropriate message
					cerr << "Error: invalid argument" << endl;
					exit(7);
			}

		}
		
		//check to see if the file exists
		//if file does not exist, create it with 000 permissions
		fd = open(argv[optind], O_CREAT, 0000);

		//close the file
		close(fd);

		//optind is element of argv[] that contains the file name

		struct stat fileperms;
	
		//determine file permissions
		if(stat(argv[optind], &fileperms) == -1)
		{
			cerr << "Error with stat." << endl;
			exit(1);
		}
	
		mode_t &mode = fileperms.st_mode;
	
		//check if the file has any permissions
		//if so, exit and display appopriate message
		if((mode & 0777) != 0)
		{
			cout << "Error: File has permissions." << endl;
			exit(6);
		}
		else
		{
			//since file has no permissions, change permissions to allow write only for the user
			chmod(argv[optind], S_IWUSR);
			
			//find how many bytes long the message to be appended to the file is
			char * mychar = argv[optind + 1];
			int num = strlen(mychar);
	
			//if the -c option is present, open the file and truncate any previous text
			//use append flag to write new text onto the end of the file
			if(gotc)
			{
				fd = open(argv[optind], O_WRONLY | O_TRUNC | O_APPEND);
				//write the message onto the end of the file
				//write the number of bytes that the message contains
				if(write(fd, argv[optind + 1], num) == -1)
				//if there was an error, exit and display appropriate error message
				cout << "Error writing to file." << endl;
				exit(5);
			}
			else
			{
				//if the -c option is not present open the file
				//open with the append flag to write new text onto the end of the file
				fd = open(argv[optind], O_WRONLY | O_APPEND);
				//write the message onto the end of the file
				//write the number of bytes that the message contains
				if(write(fd, argv[optind + 1], num) == -1)
				{
					//if there is an error, exit and display appropriate message
					cout << "Error writing to file." << endl;
					exit(4);
				}
			}
	
			//write the new line at the end of the appended message to make formatting neat
			if(write(fd, "\n", sizeof("\n")) == -1)
			{
				//if there is an error, exit and display an appropriate message
				cout << "Error writing to file." << endl;
				exit(3);
			}
	
			//close the file
			close(fd);
	
			//change the permissions back to 000
			chmod(argv[optind], 0);
		
		}
	}
	else
	{
		//if there are no arguments besides the program call, exit and display an appropriate message
		cout << "Error: No arguments entered." << endl;
		exit(2);
	}
}
