#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003F50A0(void *);
void func_003F52B8(s32, f32);
void func_003F5150(s8 *arg0, f32 fparg0) {
    s8 *p = arg0;
    p += func_003F50A0(arg0) * 4;
    func_003F52B8(*(s32 *)(p + 0xC), fparg0);
}
