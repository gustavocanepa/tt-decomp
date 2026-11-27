#include "types.h"

struct Obj_00220A08 {
    char pad[12];
    s32 unk8;
};

extern "C" void func_001058C0(void *arg0);
extern "C" char D_005794F0[];

extern "C" void func_001D2628(Obj_00220A08 *arg0) {
    if (arg0->unk8 > 0) {
        return;
    }
    return func_001058C0(D_005794F0);
}
