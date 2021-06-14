/* check for coalesce free space */
#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int main() {
   assert(Init_Mem(4096) == 0);
   void * ptr[7];

   ptr[0] = Alloc_Mem(500);
   assert(ptr[0] != NULL);

   ptr[1] = Alloc_Mem(500);
   assert(ptr[1] != NULL);

   ptr[2] = Alloc_Mem(500);
   assert(ptr[2] != NULL);

   ptr[3] = Alloc_Mem(500);
   assert(ptr[3] != NULL);

   ptr[4] = Alloc_Mem(500);
   assert(ptr[4] != NULL);

   ptr[5] = Alloc_Mem(500);
   assert(ptr[5] != NULL);

   ptr[6] = Alloc_Mem(500);
   assert(ptr[6] != NULL);

   while (Alloc_Mem(500) != NULL)
     ;

   assert(Free_Mem(ptr[1]) == 0);
   assert(Free_Mem(ptr[5]) == 0);
   assert(Free_Mem(ptr[2]) == 0);
   assert(Free_Mem(ptr[4]) == 0);
   assert(Free_Mem(ptr[3]) == 0);

   ptr[2] = Alloc_Mem(2500);
   assert(ptr[2] != NULL);

   exit(0);
}
