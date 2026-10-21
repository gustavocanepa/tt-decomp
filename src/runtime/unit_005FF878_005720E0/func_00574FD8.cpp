#include "types.h"

extern "C" void func_00574C18();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061BA08;

extern int D_007A6400;

extern "C" void *func_00574FD8(void) {
    if (D_007A6400 == 0) {
        func_00574C18();
        func_0050C6E8(&D_007A6400, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061BA08);
    }
    return &D_007A6400;
}
