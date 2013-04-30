# global variables
CC=gcc
APP=testapp
IMPL=implementation
CLEAN=$(APP) *.o
TARGETS=main.o list.o stack.o vector.o queue.o

default: $(TARGETS)
	$(CC) $(TARGETS) -o $(APP)

main.o: main.c
	$(CC) -c main.c

list.o: $(IMPL)/list.c
	$(CC) -c $(IMPL)/list.c

stack.o: $(IMPL)/stack.c
	$(CC) -c $(IMPL)/stack.c

vector.o: $(IMPL)/vector.c
	$(CC) -c $(IMPL)/vector.c

queue.o: $(IMPL)/queue.c
	$(CC) -c $(IMPL)/queue.c

.PHONY: clean
clean:
	rm -rf $(CLEAN)