#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00400CF0(s32);                             /* extern */

struct func_00564098_arg0 {
    char pad0[0xC];
    s32 unkC;
};

s32 func_00564098(struct func_00564098_arg0 *arg0) {
    s32 temp_s1;

    temp_s1 = func_00400CF0(8);
    return temp_s1 + func_00400CF0(arg0->unkC * 4);
}
