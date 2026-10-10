#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_002BD940(s32);
void func_002BF038(s32);
struct func_001CC448_arg0 {
    char pad0[0x2C];
    s32 unk2C;
    s32 unk30;
};

void func_001CC448(struct func_001CC448_arg0 *arg0) {
    s32 temp_v0;
    func_002BF038(arg0->unk30);
    temp_v0 = arg0->unk2C;
    if (temp_v0 != 0) {
        func_002BD940(temp_v0);
        arg0->unk2C = 0;
    }
}
