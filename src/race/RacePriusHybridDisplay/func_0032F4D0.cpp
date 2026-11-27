#include "types.h"

struct Item { char pad[0x1D80]; };
extern "C" void func_0032EF58(Item *);

extern "C" void func_0032F4D0(Item *items) {
    s32 i;
    for (i = 1; i >= 0; i--) {
        func_0032EF58(items++);
    }
}
