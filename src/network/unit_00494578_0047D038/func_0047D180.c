/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0047D0F0(void *);                      /* extern */
s32 func_004A5668(s32);                         /* extern */
s32 func_004AEB30(s32);                         /* extern */

struct func_0047D180_arg0 {
    char pad0[0x94];
    s32 unk94;
    char pad98[0x8];
    s32 unkA0;
};

void func_0047D180(void *arg0) {
    ((struct func_0047D180_arg0 *)arg0)->unkA0 = 1;
    func_004AEB30(arg0 + 0x64);
    func_004A5668(((struct func_0047D180_arg0 *)arg0)->unk94);
    func_0047D0F0(arg0);
}
