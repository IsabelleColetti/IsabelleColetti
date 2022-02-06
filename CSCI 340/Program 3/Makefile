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

#rule to make stack executable file
stack: stack.cc stack.h stackmain.cc
	g++ $(CXXFLAGS) -o stack stack.cc stackmain.cc

#rule to remove executable
clean:
	rm stack
