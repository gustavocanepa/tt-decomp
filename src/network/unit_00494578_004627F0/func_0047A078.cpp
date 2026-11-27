#include "types.h"

extern "C" void *func_004A4690(s32, s32);
extern "C" void *func_004AE750(s32, s32);

extern "C" void *func_0047A078(s32 size, s32 flag) {
    void *(*alloc)(s32, s32);
    if (flag) alloc = func_004AE750;
    else alloc = func_004A4690;
    return alloc(0x80, size);
}
