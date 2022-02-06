#
#  Isabelle Coletti
#  z1900409
#  CSCI 340 Section 2
#
#  I certify that this is my own work and where appropriate an extension 
#  of the starter code provided for the assignment.
#

#compiler variables
CXXFLAGS+=-Wall -Werror

#rule to link object files to executable file
twosort: twosort.o
		g++ $(CXXFLAGS) -o twosort twosort.o

#rule to compile source code files to object code
twosort.o: twosort.cc twosort.h
		g++ $(CXXFLAGS) -c twosort.cc

#rule to remove object code and executable files
clean:
		rm *.o twosort
