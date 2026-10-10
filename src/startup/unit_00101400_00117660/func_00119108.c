/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4930(s32);                         /* extern */
s32 func_004A4970(s32);                         /* extern */

struct func_00119108_arg0 {
    char pad0[0x84];
    s32 unk84;
    s32 unk88;
};

void func_00119108(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x10;
    func_004A4930(temp_s1);
    ((struct func_00119108_arg0 *)arg0)->unk84 = arg1;
    ((struct func_00119108_arg0 *)arg0)->unk88 = arg2;
    func_004A4970(temp_s1);
}
