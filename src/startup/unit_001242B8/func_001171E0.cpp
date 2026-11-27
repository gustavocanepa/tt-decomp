#include "types.h"

extern "C" s32 *D_00579774;

struct Obj00127BF0 {
    char pad[0x37C];
    s32 unk37C;
};

extern "C" void func_001171E0(void *arg0, s32 arg1, s32 arg2) {
    s32 *temp_v1 = D_00579774;

    if (temp_v1 != 0) {
        ((struct Obj00127BF0 *)(temp_v1 + arg1))->unk37C = arg2;
    }
}
