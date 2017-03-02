#####################################################
#	Makefile for CS311 HW#2 on Queues
#	Written by Brian Vargas, CSUSM
#####################################################

FC	= g++

FFLAGS	= -Wall

EXE_FILE = hw2.exe

OBJS 	= queue.o client.o

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
client.o: queue.o
