#include "types.h"

struct Struct_00323BD0 {
    char pad0[0x8];
    s32 unk8;
};

extern "C" s32 D_0057C5D0;

extern "C" void func_002BC150(struct Struct_00323BD0 *arg0) {
    s32 *p = &arg0->unk8;

    if (p != &D_0057C5D0) {
        *p = D_0057C5D0;
    }
}
