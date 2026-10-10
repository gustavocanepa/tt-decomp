#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7958(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);        /* extern */
s32 func_004AAC48(void *, s32);             /* extern */

extern char D_005C7860[];
struct func_002C0308_temp_v1 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

struct func_002C0308_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x118];
    s32 unk120;
};

void func_002C0308(void *arg0, s32 arg1) {
    s32 temp_v0;
    struct func_002C0308_temp_v1 *temp_v1;

    ((struct func_002C0308_arg0 *)arg0)->unk4 = (s32)D_005C7860;
    temp_v1 = ((struct func_002C0308_arg0 *)arg0)->unk120 - 0x10;
    temp_v0 = temp_v1->unk8 - 1;
    temp_v1->unk8 = temp_v0;
    if (temp_v0 == 0) {
        func_002BDA70(temp_v1, temp_v1->unk4 + 0x10, 4);
    }
    func_004AAC48(arg0 + 0x10, 2);
    func_002A7958(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x124, 4);
    }
}
