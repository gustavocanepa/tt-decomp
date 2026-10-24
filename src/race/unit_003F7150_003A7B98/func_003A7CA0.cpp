#include "types.h"

union Word {
    f32 f;
    s32 w;
};

extern "C" f32 func_0037C160(s32 a, f32 b);

extern "C" void func_003A7CA0(Word *arg0, Word *arg1, f32 fparg0) {
    Word *p1 = arg0 + 1;
    arg0->f = 1.0f;
    p1->f = 1.0f;
    arg0[2].f = 1.0f;
    if (arg1[0].w != 0) {
        arg0->f = func_0037C160(arg1[0].w, fparg0);
    }
    if (arg1[1].w != 0) {
        p1->f = func_0037C160(arg1[1].w, fparg0);
    }
}
