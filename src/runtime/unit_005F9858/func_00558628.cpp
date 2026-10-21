#include "types.h"

extern "C" void RaceMessageDisplay__clear(s32 arg0);

extern "C" void func_00558628(s32 arg0) {
    RaceMessageDisplay__clear(arg0 + 0x3C);
}
