#include "types.h"

extern "C" void func_00552840();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B728;

extern int D_007955C0;

extern "C" void *func_0055EA90(void) {
    if (D_007955C0 == 0) {
        func_00552840();
        func_0050C6E8(&D_007955C0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B728);
    }
    return &D_007955C0;
}
