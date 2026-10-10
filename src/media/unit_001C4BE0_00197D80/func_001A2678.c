#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_001A1FF8(void *);                      /* extern */
s32 func_001A2058();                                /* extern */
s32 func_004A8268(s32, s32);                    /* extern */
s32 func_004C24F8(s32);                             /* extern */

extern char D_005E6FE8[];
struct func_001A2678_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    char pad14[0x3BC];
    s32 unk3D0;
};

s32 func_001A2678(struct func_001A2678_arg0 *arg0) {
    if ((arg0->unk10 == 0) && (func_004A8268(func_001A2058(), (s32)D_005E6FE8) != 0)) {
        func_001A1FF8(arg0);
        arg0->unk3D0 = 2;
        return 0;
    }
    return func_004C24F8(arg0->unk4);
}
