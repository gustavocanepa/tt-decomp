#include "types.h"

extern "C" void ModelSet2__registerExternalTexSet(s32 arg0, s32 arg1);
extern "C" void func_00478C98(s32 arg0);

extern "C" void func_0017A980(void) {
    func_00478C98(0x15);
    func_00478C98(0xF);
    ModelSet2__registerExternalTexSet(0, 0);
}
