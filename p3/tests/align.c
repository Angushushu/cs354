/* first pointer returned is 8-byte aligned */
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include "mem.h"

int main() {
   assert(Init_Mem(4096) == 0);
   int* ptr = (int*) Alloc_Mem(sizeof(int));
   assert(ptr != NULL);
   assert(((int)ptr) % 8 == 0);
   exit(0);
}
