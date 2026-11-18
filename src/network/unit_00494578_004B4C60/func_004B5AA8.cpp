#include "types.h"

extern "C" s32 D_00598330;
extern "C" char D_00773FC0[];
extern "C" void func_004F45B8(void *p, s32 tag);
extern "C" void func_004B5500(void);
extern "C" void func_004BEFF8(void);

extern "C" void func_004B5AA8(void) {
    if (D_00598330 == 0) {
        D_00598330 = 1;
        func_004F45B8(D_00773FC0, 0x5042474D);
        func_004B5500();
        func_004BEFF8();
    }
}
