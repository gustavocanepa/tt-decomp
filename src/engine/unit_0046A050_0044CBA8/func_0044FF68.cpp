#include "types.h"

struct Obj00486AD0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

extern "C" f32 func_004556F0(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);

extern "C" void func_0044FF68(Obj00486AD0 *arg0) {
    func_004556F0(arg0->unk0, arg0->unk4, arg0->unk8, arg0->unkC);
}
