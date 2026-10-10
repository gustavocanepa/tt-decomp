#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00340138(s32);                         /* extern */

struct func_002CE030_arg0 {
    char pad0[0x200];
    s32 unk200;
};

void func_002CE030(void *arg0) {
    func_00340138(arg0 + 0x120);
    ((struct func_002CE030_arg0 *)arg0)->unk200 = 0;
}
