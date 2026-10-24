#include "types.h"

struct S003BABF8 {
    char pad[8];
    s32 unk8;
};

extern "C" void func_0036E680(struct S003BABF8 *arg0) {
    if (*(u8 *)&arg0->unk8 == 0) {
        arg0->unk8 = (arg0->unk8 & ~0xFF) | 1;
    }
}
