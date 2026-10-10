#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002AC0B0(s32, s32);                    /* extern */
s32 func_002C0EB0();                            /* extern */

extern char D_005C6FD0[];
struct func_002B2D60_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_002B2D60(void *arg0, s32 arg1) {
    func_002C0EB0();
    ((struct func_002B2D60_arg0 *)arg0)->unk4 = (s32)D_005C6FD0;
    func_002AC0B0(arg0 + 8, arg1);
}
