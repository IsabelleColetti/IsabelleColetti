#ifndef DOGHEADS_H
#define DOGHEADS_H

/*****************************************************
*
* CSCI 330 Section 1
* Assignment 5
* Created by Isabelle Coletti (z1900409)
* dogheads.h
*
*****************************************************/

/*
* Function cipher shifts letters in the alphabet by a number
*									entered by the user.
*
* Parameters: char* representing the buffer to be overwritten
*							const ssize_t representing the number of bytes in the buffer
*							int representing the shift specified by the user
*
* Returns nothing.
*/
void cipher(char*, const ssize_t, int);

/*
* Function rotator shifts all characters by a number entered by the user.
*
* Parameters: char* representing the buffer to be overwritten
*							const ssize_t representing the number of bytes in the buffer
*							int representing the shift specified by the user
*
* Returns nothing.
*/
void rotator(char*, const ssize_t, int);

/*
* Function hexform converts characters to hexadecimal format.
*
* Parameters: const char* representing the buffer containing the original
*										characters.
*							const ssize_t representing the number of bytes in the buffer
*							char* representing the buffer containing the characters
*										converted to hexadecimal format.
*
* Returns nothing.
*/
void hexform(const char*, const ssize_t, char*);

/*
* Function binaryform converts characters to binary format.
*
* Parameters: const char* representing the buffer containing the original
*										characters.
*							const ssize_t representing the number of bytes in the buffer
*							char* representing the buffer containing the characters
*										converted to binary format.
*
* Returns nothing.
*/
void binaryform(const char*, const ssize_t, char*);

/*
* Function hexfinder returns the correct hexadecimal value in a char for
*										the decimal number enetered.
*
* Parameters: int representing the decimal value entered.
*
* Returns a character containing one hexadecimal digit.
*/
char hexfinder(int);

#endif
