# C Data Structures

[![Build Status](https://travis-ci.org/pseudomuto/c-data-structures.svg?branch=master)](https://travis-ci.org/pseudomuto/c-data-structures)
[![codecov](https://codecov.io/gh/pseudomuto/c-data-structures/branch/master/graph/badge.svg)](https://codecov.io/gh/pseudomuto/c-data-structures)

A simple library of data structures for C. The current release contains implementations of

* Linked List
* Map
* Queue
* Stack
* Vector

## Contributing

This application uses [CMake](https://cmake.org/). Any recent (> 3.10) will do.

* `make build` (generate the build system and build the library)
* `make test` (run the unit tests)
* `BUILD_TYPE=Release make build` to generate a release version of the static library
