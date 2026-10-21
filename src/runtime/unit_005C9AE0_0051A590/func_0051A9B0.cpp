#include "types.h"

struct Obj;

struct S005CBC98 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_003FC470(Obj *arg0);

extern "C" void func_0051A9B0(struct S005CBC98 *arg0) {
    func_003FC470((Obj *)(arg0->unk10 + 0x1230));
}
