#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00572010_arg0 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x4];
    s32 unk1C;
};

s32 func_00572010(struct func_00572010_arg0 *arg0) {
    return arg0->unk1C - arg0->unk14;
}
