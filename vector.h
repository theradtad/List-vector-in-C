#ifndef VECTOR_H
#define VECTOR_H
#include "vector_iterator.h"

#include <stdbool.h>

typedef struct vector vector;
typedef struct vector_vtable vector_vtable;

//the structure for vector
struct vector
{
    void **arr;
    int sz;
    int cap;
    vector_vtable *ptr_vtable;
};

//structure for the vtable for vector that has function pointers.
struct vector_vtable
{
    int (*size)(vector *ptr_vect);
    int (*capacity)(vector *ptr_vect);
    void (*resize)(vector *ptr_vect, int n, void *val);
    bool (*empty)(vector *ptr_vect);
    void (*shrink_to_fit)(vector *ptr_vect);
    void (*assign)(vector *ptr_vect, int sz, void *value);
    void (*push_back)(vector *ptr_vect, void *g);
    void (*pop_back)(vector *ptr_vect);
    void (*insert)(vector *ptr_vect, iterator_vector ptr_iter, void *val);
    void (*erase)(vector *ptr_vect, iterator_vector ptr_iter);
    void (*clear)(vector *ptr_vect);
    void (*swap)(vector *ptr_vect1, vector *ptr_vect2);
    void **(*at)(vector *ptr_vect, int position);
    void **(*front)(vector *ptr_vect);
    void **(*back)(vector *ptr_vect);
    void **(*data)(vector *ptr_vect);
    iterator_vector (*emplace)(vector *ptr_vect, iterator_vector ptr_iter, void *element);
    void (*emplace_back)(vector *ptr_vect, void *element);
    iterator_vector *(*begin)(vector *ptr_vect);
    iterator_vector *(*end)(vector *ptr_vect);
    iterator_vector *(*rbegin)(vector *ptr_vect);
    iterator_vector *(*rend)(vector *ptr_vect);
};

void init_vector(vector *ptr_vect);
void init_vector_vtable(vector_vtable *ptr_vtable);

void add_resource_vector(vector *ptr_vect);
void clean_resource_vector();

#endif

//reserve
// iterator functions even insert and erase
// erase, resize and assign being polymorphic
//swap
// emplace and emplace_back
