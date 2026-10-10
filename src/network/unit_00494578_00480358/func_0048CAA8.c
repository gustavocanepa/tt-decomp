#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0048CAA8_arg0 {
    char pad0[0x58];
    s32 unk58;
    char pad5C[0xDC];
    s8 unk138;
};

void func_0048CAA8(struct func_0048CAA8_arg0 *arg0, s32 arg1) {
    arg0->unk58 = arg1;
    arg0->unk138 = 1;
}
