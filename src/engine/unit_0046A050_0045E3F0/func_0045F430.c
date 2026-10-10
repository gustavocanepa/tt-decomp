#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0045F430_arg0 {
    char pad0[0x9C];
    s32 unk9C;
};

void func_0045F430(struct func_0045F430_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk9C = arg2;
    func_0045FE50((s32) arg0, arg1, 0, 0, 0);
    arg0->unk9C = 0;
}
