# global variables
CC=gcc
APP=testapp
IMPL=implementation
CLEAN=$(APP) *.o
TARGETS=main.o stack.o vector.o queue.o

all: $(TARGETS)
	$(CC) $(TARGETS) -o $(APP)

main.o: main.c
	$(CC) -c main.c

stack.o: $(IMPL)/stack.c
	$(CC) -c $(IMPL)/stack.c

vector.o: $(IMPL)/vector.c
	$(CC) -c $(IMPL)/vector.c

queue.o: $(IMPL)/queue.c
	$(CC) -c $(IMPL)/queue.c

clean:
	rm -rf $(CLEAN)