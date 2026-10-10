#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_002C0FE8(s32);
void func_002C1050(s32);
struct func_00297EB0_temp_s1 {
    char pad0[0x4];
    s32 unk4;
};

void func_00297EB0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s2;
    struct func_00297EB0_temp_s1 *temp_s1;
    temp_s1 = (void *)(arg0 + 0x2C);
    temp_s2 = arg1 * 4;
    func_002C1050(*(s32 *)(temp_s1->unk4 + temp_s2));
    func_002C0FE8(arg2);
    *(s32 *)(temp_s1->unk4 + temp_s2) = arg2;
}
