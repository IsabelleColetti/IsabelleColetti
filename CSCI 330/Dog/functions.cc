/*****************************************************
*
* CSCI 330 Section 1
* Assignment 5
* Created by Isabelle Coletti (z1900409)
* functions.cc
*
*****************************************************/
#include <unistd.h>
#include "dogheads.h"
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <iostream>
//implement functions here

void cipher(char* buf, const ssize_t length, int shift)
{
	char ch;

	//iterate through every element of buf
	for(int i = 0; i < length; i++)
		{
			//set the curent element to ch
			ch = buf[i];
			
			//check to make sure ch is either in the lowercase alphabet or uppercase
			if(ch >= 'a' and ch<= 'z')
			{
				//if valid, apply the shift
				ch = ch + shift;
				//make sure the shifted character is still in the alphabet
				if(ch > 'z')
				{
					//subtract any overflow
					ch = ch - 'z' + 'a' - 1;
				}
				//reassign ch to buffer
				buf[i] = ch;
			}

			//if ch is not in the lowercase alphabet, check if it is in the uppercase alphabet
			else if(ch >= 'A' and ch <= 'Z')
			{
				//if valid, apply the shift
				ch = ch + shift;
				//make sure the shifter character is still in the alphabet
				if(ch > 'Z')
				{
					//subtract any overflow
					ch = ch - 'Z' + 'A' - 1;
				}
				//reassign ch to buffer
				buf[i] = ch;
			}
		}
}

void rotator(char* buf, const ssize_t length, int shift)
{
	char ch;

	//iterate through every element of buf
	for(int i = 0; i < length; i++)
		{
			//set the current element to ch
			ch = buf[i];
	
				//apply the shift
				ch = ch + shift;
				//check if the shift caused overflow
				if(ch > 255)
				{
					//adjust for overflow by subtracting
					ch = ch - 256;
				}
			
				//reassign ch to buf
				buf[i] = ch;
		}
}

void hexform(const char* buffer, const ssize_t length, char* outBuffer)
{
	//declare the working character, counter, and left/right characters
	char ch;
	int m = 0;
	char leftC, rightC;

	//iterate through every element of buffer
	for(int i = 0; i < length; i++)
	{
		//set the working element to ch
		ch = buffer[i];
		
		//use bitwise operator & to separate the byte into 2 groups of 4 bits
		int left = ch & 0xF0;
		int right = ch & 0x0F;

		//check that the left int is between 0 and 15
		if(left%16 >= 0 and left%16 <= 15)
		{
			//check if the left bits are divisible by 16
			if(left % 16 == 0)
			//if so, divide left by 16
				left /= 16;
			//call hexfinder to get the correct hex value for the integer
			leftC = hexfinder(left);
		}
		
		//assign the character to outBuffer
		outBuffer[m] = leftC;
		//increment the counter so right is the next index after left
		m++;
		
		//check that the right int is between 0 and 15
		if(right%16 >= 0 and right%16 <= 15)
		{
			//check if the right bits are divisible by 16
			if(right % 16 == 0)
			//if so, divide right by 16
				right /= 16;
			//call hexfinder to get the correct hex value for the integer
			rightC = hexfinder(right);
		}
		
		//assign the character to outBuffer
		outBuffer[m] = rightC;
		//increment the counter
		m++;

	}
}
	
void binaryform(const char* buf, const ssize_t length, char* outBuffer)
{
	//declare the working character, counter, and twos which contains each power of 2 to subtract
	char ch;
	int m = 0;
	int twos = 128;
	int num;

	//iterate through every element of buf
	for(int i = 0; i < length; i++)
	{
		//redeclare twos as 128 each time the loop begins
		twos = 128;
		//set current element of buf to ch
		ch = buf[i];
		//cast ch to int and save as num
		num = (int)ch;

		//continue checking if the power of two can be subtracted from num until twos reaches one
		while(twos >= 1)
		{
			//check if twos can be subtracted from num without making num negative
			if((num - twos)>= 0)
			{
				//if so, add a 1 to outBuffer
				outBuffer[m] = '1';
				//decrement num by twos
				num -= twos;
			}
			else
				//if twos cannot be subtracted from nums, add a 0 to outBuffer
				outBuffer[m] = '0';

			//increment count
			m++;
			//divide twos by 2
			twos = twos/2;
		}
	}
}


char hexfinder(int num)
{
	//return the correct hex character for the input int value
	switch(num)
	{
		case 0: return '0';
		case 1: return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';
		case 10: return 'a';
		case 11: return 'b';
		case 12: return 'c';
		case 13: return 'd';
		case 14: return 'e';
		case 15: return 'f';
		default: return '?';
	}
}
