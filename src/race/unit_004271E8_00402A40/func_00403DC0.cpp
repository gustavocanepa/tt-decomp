#include "types.h"

struct Obj {
    char pad[0x2D];
    s8 unk1A;
};

extern "C" void func_00403DC0(Obj *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0) {
        arg0->unk1A = arg2;
    }
}
