#####################################################
#	Makefile for CS311 HW#5 on Linked Lists
#	Written by Brian Vargas, CSUSM
#####################################################

FC	= g++

FFLAGS	= -Wall

EXE_FILE = hw5.exe

OBJS 	= llist.o client.o
#OBJS	= llist.o main.o

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
client.o: llist.o
#main.o: llist.o
