#include "types.h"

struct Sem { char b[0xC0]; };
extern Sem D_00776BC0[2];
extern "C" void func_004F45B8(Sem *, s32);

extern "C" void func_004BD0D8(void) {
    func_004F45B8(&D_00776BC0[0], 0x4D504731);
    func_004F45B8(&D_00776BC0[1], 0x4D504732);
}
