#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D9830[];
struct func_00411C38_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

void func_00411C38(struct func_00411C38_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unk8 = (s32)D_005D9830;
    temp_v1 = arg0->unk0;
    if (temp_v1 != 0) {
        func_004A45D0(temp_v1);
    }
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
