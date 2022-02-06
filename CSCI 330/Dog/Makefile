#CSCI 330 Section 1
#Assignment 5
#Created by Isabelle Coletti (z1900409)
CXX      = g++
CXXFLAGS = -std=c++11 -Werror -Wall

dog: dog.o functions.o dogheads.h
	$(CXX) $(CXXFLAGS) dog.o functions.o -o dog

main.o: dog.cc
	$(CXX) $(CXXFLAGS) -c dog.cc -o dog.o

functions.o: functions.cc
	$(CXX) $(CXXFLAGS) -c functions.cc -o functions.o
