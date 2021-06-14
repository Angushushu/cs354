/* second allocation is too big to fit */
#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int main() {
   assert(Init_Mem(4096) == 0);
   assert(Alloc_Mem(2048) != NULL);
   assert(Alloc_Mem(2047) == NULL);
   exit(0);
}
