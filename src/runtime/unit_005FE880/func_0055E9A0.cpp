#include "types.h"

extern "C" void func_0055E2A0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795530;

extern int D_007955B0;

extern "C" void *func_0055E9A0(void) {
    if (D_007955B0 == 0) {
        func_0055E2A0();
        func_0050C6E8(&D_007955B0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795530);
    }
    return &D_007955B0;
}
