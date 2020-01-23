// C++ File for src/thread_functor2

#include "ThreadFunctor2.h"

ThreadFunctor2::ThreadFunctor2( int* out_vals, int* in_vals, int num_in_vals ) {
   // TODO: Maybe not a good idea...
   this->out_vals = out_vals;
   this->in_vals = in_vals;
   this->num_in_vals = num_in_vals;
};

int* ThreadFunctor2::get_out_vals() { return &(out_vals[0]); }

void ThreadFunctor2::operator()() {
   try {
      if ( num_in_vals > 5 ) {
         throw std::runtime_error("Too many values for ThreadFunctor2");
      }

      for ( int index = 0; index < num_in_vals; index++ ) {
         out_vals[index] = in_vals[index] + (2*(index+1)) - 29;
         printf( "%s(): out_vals[%d] = %d\n", __func__, index, out_vals[index] );
      }
      printf( "\n" );
   } catch ( std::exception &ex ) {
      printf( "ERROR: %s\n", ex.what() );
   }

}

// end of C++ file for src/thread_functor2
