#include "types.h"

extern "C" void func_0052EA58();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793DA0;

extern int D_00794010;

extern "C" void *func_00537B08(void) {
    if (D_00794010 == 0) {
        func_0052EA58();
        func_0050C6E8(&D_00794010, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793DA0);
    }
    return &D_00794010;
}
