#include "types.h"

struct Item { char pad[0x30]; };
struct Self { char pad[0x20]; Item items[2]; };
extern "C" void func_00360630(Item *);

extern "C" void func_0035A838(Self *self) {
    Item *p = self->items;
    s32 i;
    for (i = 1; i >= 0; i--) {
        func_00360630(p++);
    }
}
