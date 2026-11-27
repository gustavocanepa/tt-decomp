#include "types.h"

struct Obj {
    char pad[0x30];
    s32 *unk30;
};

extern "C" s32 func_0054A268(Obj *arg0, s32 arg1) {
    s32 *p = arg0->unk30;
    s32 *entry = p + arg1;
    return *entry;
}
