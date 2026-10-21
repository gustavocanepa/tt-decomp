#include "types.h"

extern "C" void func_00554050();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794D00;

extern int D_00794D40;

extern "C" void *func_00554150(void) {
    if (D_00794D40 == 0) {
        func_00554050();
        func_0050C6E8(&D_00794D40, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794D00);
    }
    return &D_00794D40;
}
