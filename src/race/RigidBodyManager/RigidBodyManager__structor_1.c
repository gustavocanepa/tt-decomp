#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0050E1A8(void *);                      /* extern */
s32 func_0050E1C8(s32);                         /* extern */

extern char D_005C9258[];
extern char D_0061B704[];
extern char D_0061B710[];
struct RigidBodyManager__structor_1_arg0 {
    s32 unk0;
    char pad4[0x10];
    s32 unk14;
};

void RigidBodyManager__structor_1(struct RigidBodyManager__structor_1_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unk14 = (s32)D_005C9258;
    temp_v1 = arg0->unk0;
    if (temp_v1 != 0) {
        func_0050E1C8(temp_v1);
    }
    *(s32 *)D_0061B704 = 0;
    *(s32 *)D_0061B710 = 0;
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
