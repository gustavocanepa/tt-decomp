#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00202968();                            /* extern */
s32 func_0029B840(void *);                      /* extern */
s32 func_002A7A30(void *);                      /* extern */

extern char D_005C2D18[];
extern char D_005C3090[];
struct func_0028BA38_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
};

void func_0028BA38(void *arg0) {
    func_00202968();
    ((struct func_0028BA38_arg0 *)arg0)->unk4 = (s32)D_005C2D18;
    ((struct func_0028BA38_arg0 *)arg0)->unk2C = (s32)D_005C3090;
    func_0029B840(arg0 + 0xB4);
    func_002A7A30(arg0 + 0xB8);
}
