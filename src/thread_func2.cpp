// C++ File for thread_func2

#include "thread_func2.h"

int thread_func2( int* out_vals, const int* in_vals, const int num_in_vals ) {
   try {
      if ( num_in_vals > 5 ) {
         throw std::runtime_error("Too many values for thread_func2");
      }

      for ( int index = 0; index < num_in_vals; index++ ) {
         out_vals[index] = in_vals[index] * (8*index);
      }
      return SUCCESS;
   } catch ( std::exception &ex ) {
      printf( "ERROR: %s\n", ex.what() );
   }
}


// end of C++ file for thread_func2
