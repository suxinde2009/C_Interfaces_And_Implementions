//
//  assert.h
//  libcii
//
//  Created by Su XinDe on 14-10-13.
//  Copyright (c) 2014年 com.skyprayer. All rights reserved.
//

#ifndef __libcii__assert__
#define __libcii__assert__

#include <stdio.h>

#undef assert
#ifdef NDEBUG
#define assert(e) ((void)0)
#else
#include "except.h"
extern void assert(int e);
#define assert(e) ((void)((e)||(RAISE(Assert_Failed),0)))

#endif
#endif /* defined(__libcii__assert__) */
