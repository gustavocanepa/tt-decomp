#include "types.h"

struct S001032F0 {
    char pad0[0xB20];
    s32 unk68;
};

extern "C" void func_0041B088(void *arg0);

extern "C" void func_0017A678(S001032F0 *arg0, s32 arg1) {
    arg0->unk68 = arg1;
    func_0041B088((char *)arg0 + 0x2DC);
}
