#include "types.h"

struct Elem005F59B0 {
    char pad0[0x50];
    f32 unk50;
};

extern "C" void func_005533E0(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F59B0 *)arg0)->unk50 = fparg0;
}
