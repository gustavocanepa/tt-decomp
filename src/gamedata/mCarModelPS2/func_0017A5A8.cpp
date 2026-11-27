#include "types.h"

struct S00105708 {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_0017A698(s32 arg0, s32 arg1);

extern "C" void func_0017A5A8(struct S00105708 *arg0) {
    func_0017A698(arg0->unk0, arg0->unk4);
}
