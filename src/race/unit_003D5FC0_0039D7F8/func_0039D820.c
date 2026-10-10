/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00473178(s32);                     /* extern */
s32 func_00473F10(f32, f32, f32, f32);          /* extern */
s32 func_0047525C(s32);                         /* extern */

struct func_0039D820_arg0 {
    char pad0[0x44];
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
};

void func_0039D820(void *arg0) {
    func_00473178(2);
    func_0047525C(arg0 + 4);
    func_00473178(0);
    func_00473F10(((struct func_0039D820_arg0 *)arg0)->unk44, ((struct func_0039D820_arg0 *)arg0)->unk48, ((struct func_0039D820_arg0 *)arg0)->unk4C, ((struct func_0039D820_arg0 *)arg0)->unk50);
}
