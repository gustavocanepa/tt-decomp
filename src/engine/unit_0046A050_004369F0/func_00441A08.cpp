#include "types.h"

struct Val {
    s32 type;
    f32 v;
    Val(f32 x) {
        type = 6;
        v = x;
    }
};

extern char D_00601700[];
extern "C" void func_004A6448(void *);

extern "C" Val func_00441A08(void) {
    func_004A6448(D_00601700);
    return Val(100.0f);
}
