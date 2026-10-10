/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0034B6B8(s32, s32, void *, s32);   /* extern */

extern char D_003ADB50[];
struct func_003ADB98_arg0 {
    char pad0[0x3B0];
    s32 unk3B0;
    s32 unk3B4;
};

void func_003ADB98(struct func_003ADB98_arg0 *arg0) {
    func_0034B6B8(arg0->unk3B0, (s32)D_003ADB50, arg0, arg0->unk3B4);
}
