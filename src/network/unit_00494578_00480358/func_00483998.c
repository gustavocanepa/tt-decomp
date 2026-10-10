#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004834E8(void *);                          /* extern */
s32 func_00483628(void *, s32, void *, s32); /* extern */
s32 func_00483930(void *, s32);                 /* extern */
s32 func_00484158();                                /* extern */

struct func_00483998_arg0 {
    char pad0[0xC];
    s32 unkC;
};

void func_00483998(struct func_00483998_arg0 *arg0, s32 arg1) {
    s8 sp[0x10];
    s32 temp_s0;

    if (func_00484158() < arg0->unkC) {
        temp_s0 = func_004834E8(arg0);
        func_00483930(sp, arg1);
        func_00483628(arg0, temp_s0, sp, 0);
    }
}
