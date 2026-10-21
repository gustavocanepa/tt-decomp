#include "types.h"

extern "C" void func_0056DB98();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B968;

extern int D_00795CB8;

extern "C" void *func_0056DC88(void) {
    if (D_00795CB8 == 0) {
        func_0056DB98();
        func_0050C6E8(&D_00795CB8, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B968);
    }
    return &D_00795CB8;
}
