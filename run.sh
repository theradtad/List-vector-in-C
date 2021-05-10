#!/bin/bash
gcc -c -w client_vector.c
gcc -c -w vector.c
gcc -c -w vector_iterator.c
gcc -c -w algorithms.c
gcc -c -w iterator.c
gcc client_vector.o vector.o vector_iterator.o algorithms.o iterator.o
./a.out