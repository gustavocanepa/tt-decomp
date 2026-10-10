#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D9860[];
struct func_00412550_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_00412550(struct func_00412550_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unk4 = (s32)D_005D9860;
    temp_v1 = arg0->unk0;
    if (temp_v1 != 0) {
        func_004A45D0(temp_v1);
    }
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
