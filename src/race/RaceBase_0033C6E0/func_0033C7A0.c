#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A5018(s32);                         /* extern */
s32 func_004A5088(s32);                         /* extern */

struct func_0033C7A0_arg0 {
    char pad0[0xDD8];
    s32 unkDD8;
};

s32 func_0033C7A0(void *arg0) {
    s32 temp_s1;
    s32 temp_s2;

    temp_s1 = arg0 + 0xDA8;
    func_004A5018(temp_s1);
    temp_s2 = ((struct func_0033C7A0_arg0 *)arg0)->unkDD8;
    ((struct func_0033C7A0_arg0 *)arg0)->unkDD8 = 0;
    func_004A5088(temp_s1);
    return temp_s2;
}
