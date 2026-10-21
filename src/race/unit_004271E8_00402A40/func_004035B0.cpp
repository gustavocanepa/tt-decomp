#include "types.h"

struct Item { char pad[0xB8]; };
struct Self { s32 m0; Item items[2]; };
extern "C" void func_00403328(Item *);

extern "C" void func_004035B0(Self *self) {
    Item *p = self->items;
    s32 i;
    for (i = 1; i >= 0; i--) {
        func_00403328(p++);
    }
}
