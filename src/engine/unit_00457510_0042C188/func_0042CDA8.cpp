#include "types.h"

extern char D_0076A028[];

extern "C" void func_004A4D68(void *lock);
extern "C" void func_004A4DD8(void *lock);
extern "C" void func_0042C320(s32 on);

extern "C" void func_0042CDA8(void) {
    func_004A4D68(D_0076A028);
    func_0042C320(1);
    func_004A4DD8(D_0076A028);
}
