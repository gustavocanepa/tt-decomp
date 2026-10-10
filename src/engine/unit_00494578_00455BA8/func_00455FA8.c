#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00455FA8_arg0 {
    s32 unk0;
    char pad4[0x10];
    s32 unk14;
};

s32 func_00455FA8(struct func_00455FA8_arg0 *arg0, s32 arg1) {
    return arg0->unk0 + (arg1 + arg0->unk14);
}
