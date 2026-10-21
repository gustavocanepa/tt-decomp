#include "types.h"

extern "C" void func_00522768();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B680;

extern int D_00793A00;

extern "C" void *func_00522C50(void) {
    if (D_00793A00 == 0) {
        func_00522768();
        func_0050C6E8(&D_00793A00, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B680);
    }
    return &D_00793A00;
}
