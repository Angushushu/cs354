/* a simple 8 byte allocation */
#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int main() {
    assert(Init_Mem(4096) == 0);
    void* ptr = Alloc_Mem(8);
    assert(ptr != NULL);
    exit(0);
}
