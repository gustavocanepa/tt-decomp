#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00576300_arg0 {
    char pad0[0x1A];
    u8 unk1A;
};

void func_00576300(struct func_00576300_arg0 *arg0, s32 arg1) {
    arg0->unk1A = (u8) (arg0->unk1A | arg1);
}
