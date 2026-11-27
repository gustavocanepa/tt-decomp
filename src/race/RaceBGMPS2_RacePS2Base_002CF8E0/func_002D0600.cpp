#include "types.h"

struct Buf {
    char data[0x40];
};

extern s32 D_00582A80;
extern Buf D_005F27B0[2];

extern "C" void func_0046EE88(Buf *buf);

extern "C" void func_002D0600(void) {
    D_00582A80 ^= 1;
    func_0046EE88(&D_005F27B0[D_00582A80]);
}
