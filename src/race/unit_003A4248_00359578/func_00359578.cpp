#include "types.h"

struct Obj {
    char pad0[0x1C];
    s32 unk1C;
};

extern "C" void func_004A6500(char *arg0, const char *arg1, ...);

extern "C" void func_00359578(Obj *arg0, s32 arg1) {
    func_004A6500((char *)arg0 + 0x20, "%%0%dd", arg1);
    arg0->unk1C = 0;
}
