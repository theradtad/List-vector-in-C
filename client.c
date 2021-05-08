#include<stdio.h>
#include <stdlib.h>
#include "list.h"
#include "list_iterator.h"
#include "algorithms.h"

// bool even(int n)
// {
//     if(n%2 == 0)
//         return true;
//     return false;
// }

int main()
{
    list l1;
    init_list(&l1);
    l1.ptr_vtable->push_back(&l1,1);
    l1.ptr_vtable->push_back(&l1,3);
    l1.ptr_vtable->push_back(&l1,2);
    l1.ptr_vtable->push_back(&l1,3);
    l1.ptr_vtable->push_back(&l1,4);
    l1.ptr_vtable->push_back(&l1,3);

    l1.ptr_vtable->emplace(&l1,*(l1.ptr_vtable->begin(&l1)),0);

    printf("%d \n",(l1.ptr_vtable->back(&l1)));

    for(iterator_list *it =l1.ptr_vtable->begin(&l1); !(it->ptr_vtable->is_end(it)); it->ptr_vtable->next(it))
    {
        printf("%d ",*((it->ptr_vtable->element(it))));
    }

    printf("\n");
    iterator *it1 = (iterator*)l1.ptr_vtable->begin(&l1);
    iterator *it2 = (iterator*)l1.ptr_vtable->end(&l1); 
    printf("Min Element: %d \n",*(min_element(it1,it2)));
    printf("Count: %d \n",count(it1,it2,3));
    printf("Sorted List: ");
    sort(it1,it2);
    for(iterator *it =(iterator*)l1.ptr_vtable->begin(&l1); !(it->ptr_vtable->is_end(it)); it->ptr_vtable->next(it))
    {
        printf("%d ",*(it->ptr_vtable->element(it)));
    }
    printf("\n");
    reverse((iterator*)l1.ptr_vtable->begin(&l1), (iterator*)l1.ptr_vtable->end(&l1));
    printf("List Reverse: ");
    for(iterator *it =(iterator*)l1.ptr_vtable->begin(&l1); !(it->ptr_vtable->is_end(it)); it->ptr_vtable->next(it))
    {
        printf("%d ",*(it->ptr_vtable->element(it)));
    }
    printf("\n");
}