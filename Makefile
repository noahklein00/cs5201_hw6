###############################################################################
## -->Makefile<--
###############################################################################
##
## Programmer : Noah Klein
## Instructor : Price
## Class      : CS5201 Spring 2020
## Assignment : Homework 6 - Complex Numbers, Outer Products, and Quantum
##              Computing
## Filename   : Makefile
##
###############################################################################

###############################################################################
#This makefile will build an executable for the 2020-sp-a-hw6-nekgr8 directory.
###############################################################################

CXX = /usr/bin/g++
FLAGS = -Wall -Wextra -Wpedantic -Werror
OBJECTS = driver.o\
          qreg.o\
          gatedata.o

.SUFFIXES: .cpp

.cpp.o: $<
	${CXX} -c ${FLAGS} $< -o $@

default: all

all: hw6.out

hw6.out: ${OBJECTS}
	${CXX} ${FLAGS} ${OBJECTS} -o $@

clean:
	-@rm -f core > /dev/null 2>&1
	-@rm -f hw6.out > /dev/null 2>&1
	-@rm -f ${OBJECTS} > /dev/null 2>&1

# Dependency lists for the various source files
driver.o: driver.cpp\
          qreg.cpp\
          qreg.h\
          nVect.h\
          nVect.hpp\
          complex.h\
          complex.hpp\
          basegate.h\
          gatedata.cpp\
          gatedata.h\
          nTrix.h\
          nTrix.hpp\
          kronecker.h\
          kronecker.hpp
	g++ -c driver.cpp

qreg.o: qreg.cpp\
        qreg.h\
        nVect.h\
        nVect.hpp\
        complex.h\
        complex.hpp\
        basegate.h
	g++ -c qreg.cpp

gatedata.o: gatedata.cpp\
            gatedata.h\
            basegate.h\
            complex.h\
            complex.hpp\
            nVect.h\
            nVect.hpp\
            nTrix.h\
            nTrix.hpp\
            kronecker.h\
            kronecker.hpp
	g++ -c gatedata.cpp

# hadamard.o: hadamard.cpp\
#             hadamard.h\
#             gatedata.o
# 	g++ -c hadamard.cpp
