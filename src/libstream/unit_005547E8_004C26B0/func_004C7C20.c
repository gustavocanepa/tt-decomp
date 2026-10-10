#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C71B0(s32, s64);                        /* extern */
s32 func_004C7BA8(void *, s32);             /* extern */

struct func_004C7C20_arg0 {
    s32 unk0;
    char pad4[0x4];
    s64 unk8;
};

s32 func_004C7C20(struct func_004C7C20_arg0 *arg0) {
    if (func_004C71B0(arg0->unk0, arg0->unk8) == 0) {
        func_004C7BA8(arg0, 1);
    }
}
