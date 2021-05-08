#!/bin/bash
gcc -c client.c
gcc -c list.c
gcc -c list_iterator.c
gcc -c iterator.c
gcc -c algorithms.c
gcc client.o list.o list_iterator.o iterator.o algorithms.o
./a.out