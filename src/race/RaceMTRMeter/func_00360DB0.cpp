#include "types.h"

extern "C" void Oscillator__update(s32 arg0);

extern "C" void func_00360DB0(char *arg0) {
    Oscillator__update((s32)(arg0 + 0x4C));
}
