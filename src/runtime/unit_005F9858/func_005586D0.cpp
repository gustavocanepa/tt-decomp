#include "types.h"

extern "C" void RaceEventDisplay__clear(s32 arg0);

extern "C" void func_005586D0(s32 arg0) {
    RaceEventDisplay__clear(arg0 + 0x18C);
}
