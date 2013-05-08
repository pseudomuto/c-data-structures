# C Data Structures

[![Build Status](https://travis-ci.org/davidmuto/c-data-structures.png?branch=master)](https://travis-ci.org/davidmuto/c-data-structures)

A simple library of data structures for C. The current release contains implementations of

* Linked List (src/data-structures/list.h)
* Stack (src/data-structures/stack.h)
* Queue (src/data-structures/queue.h)
* Vector (src/data-structures/vector.h)
* Map (src/data-structures/map.h)

## Build System

This application uses the GNU Build system. To run the sample app and compile the library you will need to install the following software packages:

* [autoconf](http://ftp.gnu.org/gnu/autoconf/)
* [automake](http://ftp.gnu.org/gnu/automake/)

After downloading the above packages, run the following to install them:

	$ cd [autoconf-download-dir]
	$ ./configure
	$ make
	$ sudo make install

	$ cd [automake-download-dir]
	$ ./configure
	$ make
	$ sudo make install	

## Verifying Functionality

* Clone the repo
* Run `autoreconf --install` to generate the build system files
* Run `./configure` to configure your environment
* Run `make` to build the test project
* Run `./src/testapp` to run unit tests
* Run `make clean` to clean up

## Using the Static Library

* Run `make` to generate the static library and test application
* copy `libcdatastructures.a` and the `data-structures` folder (headers) to your application folder
* include appropriate headers for the data structures you want to use
* add `-lcdatastructures` to you compilation flags

## Sample Applications

### Coming Soon!
