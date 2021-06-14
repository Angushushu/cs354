/* write to a chunk from Alloc_Mem and check the value*/
#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int main() {
   assert(Init_Mem(4096) == 0);
   int* ptr = (int*) Alloc_Mem(sizeof(int));
   assert(ptr != NULL);
   *ptr = 42;   // check pointer is in a writeable page
   assert(*ptr == 42);
   exit(0);
}
