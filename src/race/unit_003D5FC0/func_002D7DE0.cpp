#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {

void func_001004F8(s32);
void func_00107180(s32);
void func_002D90B0(void *, s32);
struct func_002D7DE0_arg0 {
    char pad0[0x24];
    s32 unk24;
    s32 unk28;
    char pad2C[0x8];
    s32 unk34;
};

void func_002D7DE0(struct func_002D7DE0_arg0 *arg0) {
    arg0->unk24 = 1;
    if ((arg0->unk28 == 1) || (arg0->unk34 == 1)) {
        func_002D90B0(arg0, 1);
        func_00107180(1);
        func_001004F8(2);
    }
}

}
