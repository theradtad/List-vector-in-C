#include <stdio.h>
#include <stdlib.h>
#include "iterator.h"

iterator **resources;
int resource_num = 0;

// A virtual function for element of the derived classes which returns NULL.
static void **element(iterator *iter_ptr)
{
    return NULL;
}

// Virtual function for next of the derived classes.
static void next(iterator *iter_ptr)
{
    ;
}

// Virtual function for prev of the derived classes.
static void prev(iterator *iter_ptr)
{
    ;
}

// Virtual function for is_begin of the derived classes.
static bool is_begin(iterator *iter_ptr)
{
    return true;
}

// Virtual function for is_end of the derived classes.
static bool is_end(iterator *iter_ptr)
{
    return true;
}

// Virtual function to compare iterators.
static bool compare(iterator *iter_ptr1, iterator *iter_ptr2)
{
    return true;
}

// Virtual function to reset the iterator.
static void reset(iterator *iter_ptr)
{
    ;
}

static iterator_vtable iterator_vtbl = 
{
    element,
    next,
    prev,
    is_begin,
    is_end,
    compare,
    reset
};

// The init function to initialize the base class member in the derived classes.
void init_base_iterator(iterator *iter_ptr, char type, char type_of_movement)
{
    iter_ptr->ptr_vtable = &iterator_vtbl;
    iter_ptr->type_of_movement = type_of_movement;
    iter_ptr->type = type;
}

void add_resource(iterator *iter_ptr)
{
    resources = realloc(resources, sizeof(iterator *) * (resource_num + 1));
    resources[resource_num++] = iter_ptr;
}

void clean_resources()
{
    for(int i=0;i<resource_num;++i)
    {
        free(resources[i]);
    }
    free(resources);
    resource_num = 0;
}