#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0040B8A0(s32, s64);                /* extern */

extern char D_00585A30[];
struct func_0040EE48_arg0 {
    char pad0[0xA8];
    s64 unkA8;
};

void func_0040EE48(struct func_0040EE48_arg0 *arg0) {
    func_0040B8A0((s32)D_00585A30, arg0->unkA8);
}
