/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(void *);                      /* extern */

struct func_002BCD98_arg1 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
    s32 unk10;
};
struct func_002BCD98_arg0 {
    char pad0[0x8];
    void *unk8;
    s32 unkC;
};

void func_002BCD98(struct func_002BCD98_arg0 *arg0, struct func_002BCD98_arg1 *arg1) {
    void *temp_v0;

    arg1->unkC = 0;
    arg1->unk10 = 0;
    temp_v0 = arg0->unk8;
    if (temp_v0 != NULL) {
        func_004A45D0(temp_v0);
    }
    arg0->unk8 = arg1;
    arg0->unkC = (s32) (arg0->unkC - arg1->unk8);
}
