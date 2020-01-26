// C++ File for main

#include "thread_func1.h"
#include "thread_func2.h"
#include "pthread_utils.h"

#include <atomic>
 
std::atomic<bool> error_flag(false);

int main( int argc, char* argv[] ) {
  
   int num_in_vals1 = 10;
   int num_in_vals2 = 20;
   int in_vals1[num_in_vals1];
   int in_vals2[num_in_vals2];
   int out_vals1[num_in_vals1];
   int out_vals2[num_in_vals2];

   int upper  = 256;
   int lower = 12;

   gen_vals<int>( in_vals1, upper, lower, num_in_vals1 );  
   gen_vals<int>( in_vals2, upper, lower, num_in_vals2 );

   printf("Input Values 1:\n");
   printf_ints( in_vals1, num_in_vals1 );

   printf("Input Values 2:\n");
   printf_ints( in_vals2, num_in_vals2 );

   int pstatus;
   pthread_t tid1;
   pthread_t tid2;

   thread_args_t thread_args1;
   thread_args_t thread_args2;

   thread_args1.out_vals = out_vals1;
   thread_args1.in_vals = in_vals1;
   thread_args1.num_in_vals = num_in_vals1;

   thread_args2.out_vals = out_vals2;
   thread_args2.in_vals = in_vals2;
   thread_args2.num_in_vals = num_in_vals2;
  
   try_pthread_func( pstatus, "pthread_create() for thread1", 
      pthread_create( &tid1, NULL, thread_func1, (void*)&thread_args1 ) );
   try_pthread_func( pstatus, "pthread_create() for thread2", 
      pthread_create( &tid2, NULL, thread_func2, (void*)&thread_args2 ) );

   try_pthread_func( pstatus, "pthread_join() for thread1",
        pthread_join( tid1, NULL ) ); 
   try_pthread_func( pstatus, "pthread_join() for thread2",
        pthread_join( tid2, NULL ) ); 
   return 0;
}

// end of C++ file for main
