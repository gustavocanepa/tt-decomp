#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0040D420(void *);                          /* extern */

struct func_00369778_temp_s0_2 {
    char pad0[0x4];
    s32 (*unk4)(void *, s32);
};

struct func_00369778_arg0 {
    char pad0[0x4840];
    void *unk4840;
};
struct func_00369778_temp_s1 {
    char pad0[0x8];
    void *unk8;
};
struct func_00369778_temp_s0 {
    char pad0[0x38];
    s16 unk38;
};

void func_00369778(void *arg0) {
    void *temp_s0;
    struct func_00369778_temp_s0_2 *temp_s0_2;
    void *temp_s1;
    void *temp_s1_2;

    temp_s1 = ((struct func_00369778_arg0 *)arg0)->unk4840;
    temp_s0 = ((struct func_00369778_temp_s1 *)temp_s1)->unk8;
    temp_s0_2 = temp_s0 + 0x38;
    temp_s1_2 = temp_s1 + ((struct func_00369778_temp_s0 *)temp_s0)->unk38;
    temp_s0_2->unk4(temp_s1_2, func_0040D420(arg0 + 0xFD8));
}
