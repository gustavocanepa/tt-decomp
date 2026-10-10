/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001B2020(void *);                      /* extern */
s32 func_004A45D0(s32);                         /* extern */

struct func_001B1FE0_arg0 {
    char pad0[0x104];
    s32 unk104;
};

void func_001B1FE0(struct func_001B1FE0_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk104;
    if (temp_v0 != 0) {
        arg0->unk104 = 0;
        func_004A45D0(temp_v0);
    }
    func_001B2020(arg0);
}
