#include "types.h"

struct Struct_0033C158 {
    char pad[0xCFFC];
    s32 unkCF4C;
};

struct Obj;
extern "C" void func_0033A0A8(Obj *arg0, s32 arg1);

extern "C" void RacePS2Base__initializeReplayStyle(struct Struct_0033C158 *arg0) {
    arg0->unkCF4C = 0;
    func_0033A0A8((Obj *)arg0, 2);
}
