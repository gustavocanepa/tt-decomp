#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7618();                            /* extern */
s32 func_004F6678(s32, s32, s32);       /* extern */

extern char D_005B9A78[];
struct func_0023BDE0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_0023BDE0(void *arg0) {
    func_002A7618();
    ((struct func_0023BDE0_arg0 *)arg0)->unk4 = (s32)D_005B9A78;
    func_004F6678(arg0 + 0x10, 0, 0x42);
}
