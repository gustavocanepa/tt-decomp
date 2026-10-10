#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7958(void *, s32);             /* extern */
s32 func_002B1578(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */
s32 func_0054F6C0(void *);                      /* extern */

extern char D_005C7480[];
struct mGpb__structor_2_temp_s1 {
    char pad0[0x4];
    void *unk4;
};

struct mGpb__structor_2_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void mGpb__structor_2(void *arg0, s32 arg1) {
    struct mGpb__structor_2_temp_s1 *temp_s1;

    temp_s1 = arg0 + 0x14;
    ((struct mGpb__structor_2_arg0 *)arg0)->unk4 = (s32)D_005C7480;
    func_0054F6C0(temp_s1);
    func_002BDA70(temp_s1->unk4, 0xC, 4);
    func_002B1578(arg0 + 0x10, 2);
    func_002A7958(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x1C, 4);
    }
}
