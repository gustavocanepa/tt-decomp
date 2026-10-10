#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003708F0(s32, void *);                 /* extern */
s32 func_00370980(void *, s32);                     /* extern */

struct func_0036BC28_temp_s1 {
    char pad0[0x40];
    s32 unk40;
};

s32 func_0036BC28(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_s3;
    struct func_0036BC28_temp_s1 *temp_s1;

    temp_s1 = arg0 + 0x1264;
    temp_s0 = arg0 + 0x1220;
    temp_s1->unk40 = arg1;
    temp_s3 = func_00370980(temp_s1, temp_s0);
    if (arg2 != 0) {
        func_003708F0(temp_s0, temp_s1);
    }
    return temp_s3;
}
