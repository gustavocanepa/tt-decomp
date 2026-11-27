#include "types.h"

struct S_002321F0 {
    char pad[0x1D50];
    s32 unk1D58;
};

extern "C" void func_00269BF8(s32 arg0, void *arg1);

extern "C" void func_001E56D0(struct S_002321F0 *arg0) {
    func_00269BF8(arg0->unk1D58, arg0);
}
