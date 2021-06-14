/* check for coalesce free space */
#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int main() {
   assert(Init_Mem(4096) == 0);
   void * ptr[5];

   ptr[0] = Alloc_Mem(600);
   assert(ptr[0] != NULL);

   ptr[1] = Alloc_Mem(600);
   assert(ptr[1] != NULL);

   ptr[2] = Alloc_Mem(600);
   assert(ptr[2] != NULL);

   ptr[3] = Alloc_Mem(600);
   assert(ptr[3] != NULL);

   ptr[4] = Alloc_Mem(600);
   assert(ptr[4] != NULL);

   while (Alloc_Mem(600) != NULL)
     ;

   assert(Free_Mem(ptr[1]) == 0);
   assert(Free_Mem(ptr[3]) == 0);
   assert(Free_Mem(ptr[2]) == 0);

   ptr[2] = Alloc_Mem(1800);
   assert(ptr[2] != NULL);

   exit(0);
}
