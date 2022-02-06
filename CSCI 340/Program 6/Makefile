#***************************************************************************
#
#  Isabelle Coletti
#  z1900409
#  CSCI 340 Section 2
#
#  I certify that this is my own work and where appropriate an extension 
#  of the starter code provided for the assignment.
#
#***************************************************************************

#compiler variables
CXXFLAGS+=-Wall -Werror

#rule to make executable file
wordscanner: wordscanner.cc wordscanner.h
	g++ $(CXXFLAGS) -o wordscanner wordscanner.cc

#rule to remove executable
clean:
	rm wordscanner