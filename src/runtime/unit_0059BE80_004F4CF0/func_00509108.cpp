#include "types.h"

extern "C" void func_00509048(void);
extern s32 D_00793208;

extern "C" void func_00509108(void) {
    if (D_00793208 == 0) {
        D_00793208 = 1;
        return func_00509048();
    }
}
