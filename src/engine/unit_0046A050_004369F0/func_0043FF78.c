/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043AFA8(s32, s32);                    /* extern */
s32 func_00473050();                            /* extern */
s32 func_004730A8();                            /* extern */
s32 func_0047525C(s32);                         /* extern */

struct func_0043FF78_arg0 {
    char pad0[0x6E14];
    s32 unk6E14;
    char pad6E18[0x8];
    s32 unk6E20;
};

void func_0043FF78(void *arg0) {
    func_00473050();
    func_0047525C(arg0 + 0x6E3C);
    func_0043AFA8(((struct func_0043FF78_arg0 *)arg0)->unk6E20, ((struct func_0043FF78_arg0 *)arg0)->unk6E14);
    func_004730A8();
}
