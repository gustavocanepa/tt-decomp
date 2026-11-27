#include "types.h"

struct Obj {
    char pad[0x104];
    void *unk104;
};

extern "C" char D_005C9648[];
extern "C" s32 func_00318478(Obj *arg0, s32 arg1, s32 arg2);

extern "C" s32 func_00318418(Obj *arg0) {
    arg0->unk104 = D_005C9648;
    return func_00318478(arg0, 0, 0);
}
