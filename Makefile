# global variables
CC=gcc
APP=testapp
IMPL=implementation
DIST=distribution
CLEAN=$(APP) *.o *.a $(DIST)
TARGETS=main.o list.o stack.o vector.o queue.o map.o

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

map.o: $(IMPL)/map.c
	$(CC) -c $(IMPL)/map.c

# make a static library
.PHONY: dist
dist: $(TARGETS)
	make clean
	mkdir -p $(DIST)
	cp -r data-structures/ $(DIST)/data-structures
	make
	ar rsc $(DIST)/libCDataStructures.a $(TARGETS)

# build and run tests
.PHONY: tests
tests:
	make clean
	make
	./$(APP)

# clean temp files
.PHONY: clean
clean:
	rm -rf $(CLEAN)