// C++ File for thread_func1

#include "thread_func1.h"

extern std::atomic<bool> error_flag;

void* thread_func1( void* args ) {
   thread_args_t* thread_args = (thread_args_t*)args;
   
   for ( int index = 0; index < thread_args->num_in_vals; index++ ) {
      thread_args->out_vals[index] = thread_args->in_vals[index]/(2*(index+1));
      printf( "thread1: out_vals[%d] = %d\n", index, thread_args->out_vals[index] );

      if ( index > 5 ) {
         printf( "thread1: Simulating error. Index is %d of %d. Exiting and setting error flag for thread 2 to see.\n",
            index, thread_args->num_in_vals );
         error_flag = true;
         break;
      }

      if (error_flag.load()) {
         printf( "thread1: Exiting due to error detected.\n" );
         return NULL;
      }
   }
   printf( "\n" );   
   return NULL;
}


// end of C++ file for thread_func1
