# define common sources
XSOURCES = implementation/list.c implementation/vector.c implementation/stack.c implementation/queue.c implementation/map.c

# make testapp
bin_PROGRAMS = testapp
testapp_SOURCES = main.c $(XSOURCES)

# make static library
noinst_LIBRARIES = libcdatastructures.a
libcdatastructures_a_SOURCES = $(XSOURCES)