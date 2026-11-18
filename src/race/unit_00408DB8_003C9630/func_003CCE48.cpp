#include "types.h"

struct Item { char pad[0x154]; };
extern "C" void func_003CC0A0(Item *);

extern "C" void func_003CCE48(Item *items) {
    s32 i;
    for (i = 6; i >= 0; i--) {
        func_003CC0A0(items++);
    }
}
