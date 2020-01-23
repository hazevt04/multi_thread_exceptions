#ifndef __THREAD_FUNCTOR1_H__
#define __THREAD_FUNCTOR1_H__

#include "utils.h"

class ThreadFunctor1 {
   public:
      ThreadFunctor1( int* out_vals, int* in_vals, int num_in_vals );
      int* get_out_vals();
      void operator()();
   private:
      // TODO: Switch to smart pointers?
      int* out_vals;
      int* in_vals;
      int num_in_vals;
};

#endif // end of include/thread_functor1
