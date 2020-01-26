// C++ File for thread_func2

#include "thread_func2.h"
extern std::atomic<bool> error_flag;

void* thread_func2( void* args ) {
   thread_args_t* thread_args = (thread_args_t*)args;

   for ( int index = 0; index < thread_args->num_in_vals; index++ ) {
      thread_args->out_vals[index] = thread_args->in_vals[index] * (8*(index+1));
      printf( "thread2: out_val[%d] = %d\n", index, thread_args->out_vals[index] );
      
      if ( index > 10 ) {
         printf( "thread2: Simulating error. Index is %d of %d. Exiting and setting error flag for thread 1 to see.\n",
            index, thread_args->num_in_vals );
         error_flag = true;
         break;
      }

      if (error_flag.load()) {
         printf( "thread2: Exiting due to error detected.\n" );
         return NULL;
      }
   
   } // end of for ( int index = 0; index < thread_args->num_in_vals; index++ ) {
   printf( "\n" );
   return NULL;
}


// end of C++ file for thread_func2
