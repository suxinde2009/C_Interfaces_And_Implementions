//
//  list.h
//  libcii
//
//  Created by Su XinDe on 14-10-13.
//  Copyright (c) 2014年 com.skyprayer. All rights reserved.
//

#ifndef libcii_list_h
#define libcii_list_h
#define T List_T
typedef struct T *T;
struct T {
    T rest;
    void *first;
};
extern T        List_append (T list, T tail);
extern T        List_copy   (T list);
extern T        List_list   (void* x, ...);
extern T        List_pop    (T list, void **x);
extern T        List_push   (T list, void *x);
extern T        List_reverse(T list);
extern int      List_length (T list);
extern void     List_free   (T *list);
extern void     List_map    (T list,
                             void apply(void **x, void *cl),
                             void *cl);
extern void   **List_toArray(T list, void *end);
#undef T
#endif






