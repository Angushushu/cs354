/*a few allocations in multiples of 4 bytes*/
#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int main() {
   assert(Init_Mem(4096) == 0);
   assert(Alloc_Mem(4) != NULL);
   assert(Alloc_Mem(8) != NULL);
   assert(Alloc_Mem(16) != NULL);
   assert(Alloc_Mem(24) != NULL);
   exit(0);
}
