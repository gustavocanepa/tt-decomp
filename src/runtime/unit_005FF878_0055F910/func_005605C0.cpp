#include "types.h"

extern "C" void func_00560568();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795780;

extern int D_00795770;

extern "C" void *func_005605C0(void) {
    if (D_00795770 == 0) {
        func_00560568();
        func_0050C6E8(&D_00795770, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795780);
    }
    return &D_00795770;
}
