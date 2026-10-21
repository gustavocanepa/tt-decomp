#include "types.h"

struct Obj {
    char pad[0x1C];
    s32 unk1C;
};

extern "C" s32 *func_002A4960(s32 *arg0, Obj *arg1) {
    *arg0 = arg1->unk1C;
    return arg0;
}
