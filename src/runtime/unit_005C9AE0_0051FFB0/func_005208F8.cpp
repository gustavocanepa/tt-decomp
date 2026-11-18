#include "types.h"

extern "C" void func_005206C0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B658;

extern int D_00793890;

extern "C" void *func_005208F8(void) {
    if (D_00793890 == 0) {
        func_005206C0();
        func_0050C6E8(&D_00793890, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B658);
    }
    return &D_00793890;
}
