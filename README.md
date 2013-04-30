# C Data Structures

A simple library of data structures for C. The current release contains implementations of

* Linked List (data-structures/list.h)
* Stack (data-structures/stack.h)
* Queue (data-structures/queue.h)
* Vector (data-structures/vector.h)
* Map (data-structures/map.h)

## Verifying Functionality

* Clone the repo
* Run `make tests` to ensure the application compiles and all tests pass

## Building the static library (only tested on OSX so far)

* Run `make dist` to generate the .a file and headers
* Copy `distribution` folder to your application
* Include headers as needed

## Build System

This application uses the GNU Build system.