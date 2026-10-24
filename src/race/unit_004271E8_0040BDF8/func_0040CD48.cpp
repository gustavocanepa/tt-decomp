#include "types.h"

struct Obj {
    char pad[0x15B];
    s8 unk15B;
    s8 unk15C;
};

extern "C" s32 func_0040CD48(Obj *arg0) {
    arg0->unk15B = 0;
    arg0->unk15C = 0;
    return 1;
}
