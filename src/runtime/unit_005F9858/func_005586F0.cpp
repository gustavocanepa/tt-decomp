#include "types.h"

extern "C" void RaceEventDisplay__addEvent(s32 arg0);

extern "C" void func_005586F0(s32 arg0) {
    RaceEventDisplay__addEvent(arg0 + 0x18C);
}
