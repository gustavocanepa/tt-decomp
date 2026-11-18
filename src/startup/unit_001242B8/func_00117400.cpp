#include "types.h"

extern "C" s32 *D_00579774;

struct Obj00127BB8 {
    char pad[0x458];
    s32 unk364;
};

extern "C" void func_00117400(void *arg0, s32 arg1, s32 arg2) {
    s32 *temp_v1 = D_00579774;

    if (temp_v1 != 0) {
        ((struct Obj00127BB8 *)(temp_v1 + arg1))->unk364 = arg2;
    }
}
