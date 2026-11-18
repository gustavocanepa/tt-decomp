#include "types.h"

struct Sub {
    char pad[0x617];
    u8 unk5FB;
};

extern "C" void func_00300170(void *arg0) {
    struct Sub *temp_a0 = (struct Sub *)((char *)arg0 + 0x104);

    if (temp_a0->unk5FB != 0 && temp_a0->unk5FB != 0xFF) {
        temp_a0->unk5FB = temp_a0->unk5FB + 0xFF;
    }
}
