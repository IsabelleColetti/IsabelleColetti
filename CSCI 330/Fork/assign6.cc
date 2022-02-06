/*****************************************************
*
* CSCI 330 Section 1
* Assignment 6
* Created by Isabelle Coletti (z1900409)
* assign6.cc
*
*****************************************************/
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	//declare pipe file descriptors
	int pipefd[2];
	int rs;
	//initialize isDone to false to enter loop
	bool isDone = false;
	//character arrays able to hold 255 characters from user input
	char com1[256];
	char com2[256];

	int looper = 0;
  int count = 0;
  int count2 = 0;
	int stin;
	//char pointers to hold 5 command line arguments per command
  char * arg1;
	char * arg2;
	char * arg3;
	char * arg4;
	char * arg5;
  char * Sarg1;
	char * Sarg2;
	char * Sarg3;
	char * Sarg4;
	char * Sarg5;
	//char pointers to hold each command without command line arguments
  char * command1;
  char * command2;
  char * option;

	//enter loop to continue while the user has not entered "done"
	while(isDone == false)
	{
		//if this is the first time running the loop, ask for commands here
		if(looper == 0)
		{
			//ask for command 1, then get the entire line (255 characters) of user input
			cout << "command 1? ";
			std::cin.getline(com1, 255);

			//check if the command entered is "done", and if so, exit loop and exit program
			if(strcmp(com1, "done") == 0)
			{
				//change isDone to true
				isDone = true;
				exit(5);
			}

			//ask for command 2, then get the entire line (255 characters) of user input
			cout << "command 2? ";
			std::cin.getline(com2, 255);

			//add to looper to signify that the first pass of the loop has occurred
			looper++;
		}

		//set count to 0 to begin the switch at case 0
    count = 0;

		//separate the first command by saving everything before the first space into command1
    command1 = strtok(com1, " ");

		//continue separating the characters between spaces and saving them into the args in the order
		//they were entered in until there is nothing left
    while((option = strtok(NULL, " ")) != NULL)
    {
			//save the argument into a variable based on how many arguments have been counted so far
      switch(count)
      {
        case 0: arg1 = option; break;
        case 1: arg2 = option; break;
        case 2: arg3 = option; break;
        case 3: arg4 = option; break;
        case 4: arg5 = option; break;
				//if count is over 4, print an error and exit because the user entered too many arguments
        default: cout << "Too many command line options in first command." << endl; return -1;
      }
			//increment count
      count++;
    }

		//set the count for the second command to 0 to begin the switch at case 0
    count2 = 0;

		//separate the second command by saving everything before the first space into command2
    command2 = strtok(com2, " ");

		//continue to separate the characters between spaces and save them into the args in the same order
		//they were entered in until there is nothing left
    while((option = strtok(NULL, " ")) != NULL)
    {
			//save the argument into a variable based on how many arguments have been counted so far
      switch(count2)
      {
        case 0: Sarg1 = option; break;
        case 1: Sarg2 = option; break;
        case 2: Sarg3 = option; break;
        case 3: Sarg4 = option; break;
        case 4: Sarg5 = option; break;
				//if count2 is over 4, print an error and exit because the user entered too many arguments
        default: cout << "Too many command line options in second command." << endl; return -1;
      }
			//increment count2
      count2++;
    }

		//declare the pipe
		rs = pipe(pipefd);
		//check if there was an error creating the pipe
		if(rs == -1)
		{
			//if so, print a message and exit
			perror("Error with pipe");
			exit(1);
		}

		//fork
		pid_t pid = fork();
		
		//check if there was an error
		if(pid == -1)
		{
			//if so, print message and exit
			perror("Fork error");
			exit(1);
		}
		//child process
		if(pid == 0)
		{
			//close read end of pipe
			close(pipefd[0]);

			//close standard output
			close(1);
			
			//duplicate write end of pipe into standard output
			dup(pipefd[1]);

			//close write end of pipe
      close(pipefd[1]);

			//call execlp with the correct arguments based on what count left off on
      switch(count)
      {
        case 0: rs = execlp(command1, command1, nullptr); break;
        case 1: rs = execlp(command1, command1, arg1, nullptr); break;
        case 2: rs = execlp(command1, command1, arg1, arg2, nullptr); break;
        case 3: rs = execlp(command1, command1, arg1, arg2, arg3, nullptr); break;
        case 4: rs = execlp(command1, command1, arg1, arg2, arg3, arg4, nullptr); break;
        case 5: rs = execlp(command1, command1, arg1, arg2, arg3, arg4, arg5, nullptr); break;
      }

			//check if there was an error with exec
      if(rs < 0)
      {
				//if so, print message and exit
        perror("Error with exec 1");
        return -1;
      }
      
			exit(3);

		}	
		else //we are in the parent now
		{
				//wait for the child to finish
				wait(nullptr);

				//close write end of pipe
				close(pipefd[1]);

				//duplicate standard input to stdin
				stin = dup(0);

				//close standard input
				close(0);

				//duplicate read end of pipe into standard input
				dup(pipefd[0]);

				//close read end of pipe
				close(pipefd[0]);

				//fork
				pid = fork();

				//check if there was an error
				if(pid == -1)
				{
					//if so, print message and exit
					perror("Fork error");
					exit(1);
				}

				//check if we are in the second child
				if(pid == 0)
				{
					//call execlp with the correct arguments based on what count2 left off on
          switch(count2)
          {
            case 0: rs = execlp(command2, command2, nullptr); break;
            case 1: rs = execlp(command2, command2, Sarg1, nullptr); break;
            case 2: rs = execlp(command2, command2, Sarg1, Sarg2, nullptr); break;
            case 3: rs = execlp(command2, command2, Sarg1, Sarg2, Sarg3, nullptr); break;
            case 4: rs = execlp(command2, command2, Sarg1, Sarg2, Sarg3, Sarg4, nullptr); break;
            case 5: rs = execlp(command2, command2, Sarg1, Sarg2, Sarg3, Sarg4, Sarg5, nullptr); break;
          }

					//check if there was an error with exec
          if(rs < 0)
          {
						//if so, print message and exit
            perror("Error with exec 2");
            return -1;
          }
					exit(4);
				}
				else //we are in the parent
				{
					//wait for the second child to finish
					wait(NULL);
				}
				//duplicate value from stin into file descriptor 0
        dup2(stin, 0);
				
				//ask for command 1 and save 255 characters of user input
				cout << "command 1? ";
				std::cin.getline(com1, 255);

				//check if the user entered "done"
				if(strcmp(com1, "done") == 0)
				{
					//if so, change isDone to true to exit the loop
					isDone = true;
					exit(4);
				}

				//ask for command 2 and save 255 characters of user input
				cout << "command 2? ";
				std::cin.getline(com2, 255);
			
    }
		
	}
	

	return 0;
}
