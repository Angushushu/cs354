/* Check for best fit implementation */
#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int main() {
   assert(Init_Mem(4096) == 0);
   void* ptr[9];
   void* test;

   ptr[0] = Alloc_Mem(300);
   assert(ptr[0] != NULL);

   ptr[1] = Alloc_Mem(200);
   assert(ptr[1] != NULL);

   ptr[2] = Alloc_Mem(200);
   assert(ptr[2] != NULL);

   ptr[3] = Alloc_Mem(100);
   assert(ptr[3] != NULL);

   ptr[4] = Alloc_Mem(200);
   assert(ptr[4] != NULL);

   ptr[5] = Alloc_Mem(800);
   assert(ptr[5] != NULL);

   ptr[6] = Alloc_Mem(500);
   assert(ptr[6] != NULL);

   ptr[7] = Alloc_Mem(700);
   assert(ptr[7] != NULL);

   ptr[8] = Alloc_Mem(300);
   assert(ptr[8] != NULL);

   assert(Free_Mem(ptr[1]) == 0);
   assert(Free_Mem(ptr[3]) == 0);
   assert(Free_Mem(ptr[5]) == 0);
   assert(Free_Mem(ptr[7]) == 0);

   test = Alloc_Mem(50);
   assert(
           (
             ((unsigned long int)test >= (unsigned long int)ptr[3])
             &&
             ((unsigned long int)test < (unsigned long int)ptr[4])
           )
           ||
           (
             ((unsigned long int)test >= (unsigned long int)ptr[3])
             &&
             ((unsigned long int)test < (unsigned long int)ptr[2])
           )
         );
   exit(0);
}
