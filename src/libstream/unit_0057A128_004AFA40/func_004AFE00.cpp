#include "types.h"

struct Obj {
    f32 unk0;
    f32 unk4;
};

extern "C" struct Obj *func_004AFE00(struct Obj *arg0, f32 fparg0) {
    arg0->unk0 = arg0->unk0 - arg0->unk4 * fparg0;
    return arg0;
}
