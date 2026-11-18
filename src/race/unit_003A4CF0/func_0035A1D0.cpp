#include "types.h"

extern "C" void AutomaticFader__fadeout(s32 arg0);

extern "C" void func_0035A1D0(s32 arg0) {
    AutomaticFader__fadeout(arg0 + 0x54);
}
