/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0034C5F0(s32, void *);                 /* extern */
s32 func_0034C6D8(s32);                         /* extern */

struct func_0034A820_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xC8];
    s32 unkD0;
};

void func_0034A820(void *arg0) {
    ((struct func_0034A820_arg0 *)arg0)->unkD0 = 0;
    func_0034C6D8(((struct func_0034A820_arg0 *)arg0)->unk4);
    func_0034C5F0(((struct func_0034A820_arg0 *)arg0)->unk4, arg0 + 0x9C);
}
