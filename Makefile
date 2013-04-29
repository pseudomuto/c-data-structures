# global variables
CC=gcc
APP=testapp
IMPL=implementation
CLEAN=$(APP) *.o

all: main.o stack.o vector.o
	$(CC) main.o stack.o vector.o -o $(APP)

main.o: main.c
	$(CC) -c main.c

stack.o: $(IMPL)/stack.c
	$(CC) -c $(IMPL)/stack.c

vector.o: $(IMPL)/vector.c
	$(CC) -c $(IMPL)/vector.c

clean:
	rm -rf $(CLEAN)