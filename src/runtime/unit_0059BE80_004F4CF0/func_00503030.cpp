#include "types.h"

extern "C" void func_00502A60(s32 a0, s32 a1, s32 a2, void *a3);

extern "C" void func_00503030(s32 a0, s32 a1, s32 a2)
{
    char buf[0x10];
    func_00502A60(a0, a1, a2, buf);
}
