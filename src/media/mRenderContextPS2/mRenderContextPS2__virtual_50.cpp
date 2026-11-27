#include "types.h"

struct Obj;

extern "C" f32 func_001E4CA8(struct Obj *arg0);
extern "C" s32 func_002134A8(s32 arg0, f32 arg1);
extern "C" void func_00477DC0(s32 arg0);

extern "C" void mRenderContextPS2__virtual_50(struct Obj *arg0, s32 arg1) {
    s32 s0 = arg1;
    f32 f = func_001E4CA8(arg0);

    func_00477DC0(func_002134A8(s0, f));
}
