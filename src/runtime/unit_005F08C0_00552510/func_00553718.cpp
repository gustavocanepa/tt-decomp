#include "types.h"

struct Obj {
    char pad[0x290];
    s64 unk268;
};

extern "C" void func_00553718(Obj *arg0) {
    arg0->unk268 = (arg0->unk268 & ~(0xFFLL << 8)) | (1LL << 8);
}
