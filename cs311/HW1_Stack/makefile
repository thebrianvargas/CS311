#####################################################
#	Makefile for CS311 HW#1 on Stacks
#	Written by Brian Vargas, CSUSM
#####################################################

FC	= g++

FFLAGS	= -Wall

EXE_FILE = hw1.exe

OBJS 	= stack.o main.o

.PHONY: clean
#####################################################
#COMPILING AND LINKING

$(EXE_FILE) : $(OBJS)
	@$(FC) $(FFLAGS) $(OBJS) -o $(EXE_FILE)
	@echo "Code is now linking..."

%.o: %.cpp
	$(FC) $(FFLAGS) -c $<

#####################################################
#SOME USEFUL COMMANDS
clean:
	@rm -f *.o *.exe

#####################################################
#FILE DEPENDENCIES
main.o: stack.o
