#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_0057ABA8[];
struct func_00526BA8_arg0 {
    char pad0[0xC];
    s32 unkC;
};

s32 func_00526BA8(struct func_00526BA8_arg0 *arg0) {
    s32 temp_v0;

    if (arg0 != NULL) {
        temp_v0 = *(s32 *)(s32)D_0057ABA8;
        arg0->unkC = temp_v0;
        *(s32 *)(s32)D_0057ABA8 = (s32) arg0;
    }
    return *(s32 *)(s32)D_0057ABA8;
}
