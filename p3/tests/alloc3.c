/* many odd sized allocations */
#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int main() {
   assert(Init_Mem(4096) == 0);
   assert(Alloc_Mem(1) != NULL);
   assert(Alloc_Mem(5) != NULL);
   assert(Alloc_Mem(14) != NULL);
   assert(Alloc_Mem(8) != NULL);
   assert(Alloc_Mem(1) != NULL);
   assert(Alloc_Mem(4) != NULL);
   assert(Alloc_Mem(9) != NULL);
   assert(Alloc_Mem(33) != NULL);
   assert(Alloc_Mem(55) != NULL);
   exit(0);
}
