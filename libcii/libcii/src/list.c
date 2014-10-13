//
//  list.c
//  libcii
//
//  Created by Su XinDe on 14-10-13.
//  Copyright (c) 2014年 com.skyprayer. All rights reserved.
//

#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>

#include "list.h"
#include "mem.h"
#include "except.h"
#include "assert.h"


#define T List_T

T List_append(T list, T tail)
{
    T *p = &list; // get the head of list
    while (p) {
        p = &(*p)->rest; // move p to the end of list
    }
    *p = tail; //
    return list;
}

T List_copy(T list)
{
    T head, *p = &head;
    for (; list; list = list->rest)
    {
        NEW(*p);
        (*p)->first = list->first;
        p = &(*p)->rest;
    }
    *p = NULL;
    return head;
}

T  List_list(void* x, ...)
{
    va_list ap;
    T list, *p = &list;
    va_start(ap, x);
    for (; x; x = va_arg(ap, void*)) {
        NEW(*p);
        (*p)->first = x;
        p = &(*p)->rest;
    }
    *p = NULL;
    va_end(ap);
    return list;
}

T List_pop(T list, void **x)
{
    if (list) {
        T head = list->rest;
        if (x) {
            *x = list->first;
        }
        FREE(list);
        return head;
    }else {
        return list;
    }
    
}

T List_push(T list, void *x)
{
    T p;
    NEW(p);
    p->first = x;
    p->rest = list;
    return p;
}

T List_reverse(T list)
{
    T head = NULL, next;
    for (; list; list = next) {
        next = list->rest;
        list->rest = head;
        head = list;
    }
    return head;
}

int List_length(T list)
{
    int length = 0;
    for (length = 0; list; list = list->rest) {
        length++;
    }
    return length;
}

void List_free(T *list)
{
    T next;
    assert(list);
    for ( ; *list; *list = next) {
        next = (*list)->rest;
        FREE(*list);
    }
}

void List_map(T list,
              void apply(void **x, void *cl),
              void *cl)
{
    for ( ; list; list = list->rest) {
        apply(&list->first, cl);
    }
    
}

void **List_toArray(T list, void *end)
{
    int idx, length = List_length(list);
    void **array = ALLOC((length+1)*sizeof(*array));
    for (idx = 0; idx < length; idx++) {
        array[idx] = list->first;
        list = list->rest;
    }
    array[idx] = end;
    return array;
}