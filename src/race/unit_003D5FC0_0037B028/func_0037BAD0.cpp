#include "types.h"

struct Struct_003446B8;

struct Obj {
    char pad[4];
    struct Struct_003446B8 *unk4;
};

extern "C" s32 func_002E5D50(struct Struct_003446B8 *arg0);

extern "C" s32 func_0037BAD0(struct Obj *arg0) {
    return func_002E5D50(arg0->unk4) != 0;
}
