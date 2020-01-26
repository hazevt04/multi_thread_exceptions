#ifndef __PTHREAD_UTILS_H__
#define __PTHREAD_UTILS_H__

#include "utils.h"

#include <pthread.h>

inline std::string decode_pthread_status( const pthread_t tid ) {
   std::string result_str;
   switch( tid ) {
      case EAGAIN:
         result_str = "Insufficient resources to create another thread";
         break;
      case EINVAL:
         result_str = "Invalid settings in attr";
         break;
      case EPERM:
         result_str = "No permission to set the scheduling policy and and parameters specified in attr";
         break;
      default:
         result_str = "Unknown pthread result";
   }
   return result_str;
}

#define check_pthread_status( status, msg ) { \
   if ( status != 0 ) { \
      printf( "%s(): ERROR: " #msg ": %s\n", __func__, \
         decode_pthread_status( status ).c_str() ); \
      exit(EXIT_FAILURE); \
   } \
}


#define try_pthread_func(status, msg, func) { \
  status = func; \
  check_pthread_status( status, msg ); \
}

#endif // end of __PTHREAD_UTILS_H__
