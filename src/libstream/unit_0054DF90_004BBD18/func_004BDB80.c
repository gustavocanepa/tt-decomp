#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004CC818(s32);
s32 func_004FA820(s32);                         /* extern */
s32 func_004FAAA0(s32);                     /* extern */

extern char D_00613268[];
struct func_004BDB80_arg0 {
    char pad0[0x24];
    s32 unk24;
    s32 unk28;
    char pad2C[0xC];
    s32 unk38;
    s32 unk3C;
};

void func_004BDB80(struct func_004BDB80_arg0 *arg0, s32 arg1) {
    func_004F6678(arg0, 0, 0x44);
    arg0->unk3C = arg1;
    arg0->unk28 = (s32) ((func_004CC818(1) & 0x0FFFFFFF) | 0x20000000);
    arg0->unk24 = func_004CC818(2);
    func_004FAAA0(0);
    arg0->unk38 = func_004FA820((s32)D_00613268);
}
