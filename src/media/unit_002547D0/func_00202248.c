#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_001C2A20(void *, s32);
void func_001C2E70(void *);
s32 func_001C51E8(s32);
void func_001FF018(s32, void *);
struct func_00202248_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_00202248(struct func_00202248_arg0 *arg0) {
    s32 sp[4];
    s32 temp_s1;
    arg0->unk10 = 0;
    func_001C2E70(sp);
    temp_s1 = func_001C51E8(sp[0]);
    func_001C2A20(sp, 2);
    arg0->unk18 = arg0->unk14;
    func_001FF018(temp_s1, arg0);
}
