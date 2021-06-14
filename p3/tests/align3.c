/* many odd sized allocations checked for alignment */
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include "mem.h"

int main() {
    assert(Init_Mem(4096) == 0);
    void* ptr[9];
    ptr[0] = Alloc_Mem(1);
    ptr[1] = (Alloc_Mem(5));
    ptr[2] = (Alloc_Mem(14));
    ptr[3] = (Alloc_Mem(8));
    ptr[4] = (Alloc_Mem(1));
    ptr[5] = (Alloc_Mem(4));
    ptr[6] = (Alloc_Mem(9));
    ptr[7] = (Alloc_Mem(33));
    ptr[8] = (Alloc_Mem(55));
   
    for (int i = 0; i < 9; i++) {
        assert(((int)ptr[i]) % 8 == 0);
    }
    exit(0);
}
