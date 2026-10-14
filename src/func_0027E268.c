#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001E9558(s32, s32);                    /* extern */
s32 func_00206DF8(s32);                             /* extern */
s32 func_0020D780(s32, s32);                    /* extern */
s32 func_0020D888();                                /* extern */

struct func_0027E268_arg0 {
    char pad0[0xBC];
    s32 unkBC;
};

void func_0027E268(struct func_0027E268_arg0 *arg0, s32 arg1) {
    s32 temp_s0;

    if (func_0020D888() != 0) {
        func_001E9558(arg1, 0);
    }
    temp_s0 = arg0->unkBC;
    if (temp_s0 != 0) {
        do {
            func_0020D780(temp_s0, 0);
            temp_s0 = func_00206DF8(temp_s0);
        } while (temp_s0 != 0);
    }
}
