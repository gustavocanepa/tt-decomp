#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AE6D8(s32);                             /* extern */
s32 func_004F64C4(s32, s32, s32);               /* extern */
s32 func_004F6678(s32, s32, s32);           /* extern */
s32 func_004F7B74();                            /* extern */

struct func_001A1E60_arg0 {
    char pad0[0x20];
    s32 unk20;
    s32 unk24;
    s32 unk28;
};

void func_001A1E60(struct func_001A1E60_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s0;
    s32 temp_v0;

    func_004F7B74();
    temp_s0 = (arg3 + 0x3F) & ~0x3F;
    temp_v0 = func_004AE6D8(temp_s0);
    arg0->unk28 = temp_v0;
    func_004F6678(temp_v0, 0, temp_s0);
    func_004F64C4(arg0->unk28, arg2, arg3);
    arg0->unk20 = arg3;
    arg0->unk24 = temp_s0;
}
