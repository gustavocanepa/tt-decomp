#include "types.h"

struct S00323CD8 {
    char pad0[0x8];
    s32 unk8;
};

extern "C" s32 func_002B1090(s32 arg0);

extern "C" void func_002BC250(struct S00323CD8 *arg0) {
    func_002B1090(arg0->unk8);
}
