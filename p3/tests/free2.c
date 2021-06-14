/* a few allocations in multiples of 4 bytes followed by frees */
#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int main() {
   assert(Init_Mem(4096) == 0);
   void* ptr[4];

   ptr[0] = Alloc_Mem(4);
   ptr[1] = Alloc_Mem(8);
   assert(Free_Mem(ptr[0]) == 0);
   assert(Free_Mem(ptr[1]) == 0);

   ptr[2] = Alloc_Mem(16);
   ptr[3] = Alloc_Mem(4);
   assert(Free_Mem(ptr[2]) == 0);
   assert(Free_Mem(ptr[3]) == 0);

   exit(0);
}
