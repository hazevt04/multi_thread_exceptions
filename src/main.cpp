// C++ File for main

#include "thread_func1.h"
#include "thread_func2.h"

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

  std::future<int> thread1_result = std::async( std::launch::async, &thread_func1, 
      &(out_vals1[0]), &(in_vals1[0]), num_in_vals1 );
  std::future<int> thread2_result = std::async( std::launch::async, &thread_func2,
      &(out_vals2[0]), &(in_vals2[0]), num_in_vals2 );
  return 0;
}

// end of C++ file for main
