#ifndef __THREAD_ARGS_H__
#define __THREAD_ARGS_H__

#include "utils.h"

typedef struct thread_args_s {
   int* out_vals;
   int* in_vals;
   int num_in_vals;
} thread_args_t;

#endif // end of __THREAD_ARGS_H__
