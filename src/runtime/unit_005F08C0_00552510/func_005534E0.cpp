#include "types.h"

struct Elem005F5AB0 {
    char pad0[0x58];
    f32 unk58;
};

extern "C" void func_005534E0(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F5AB0 *)arg0)->unk58 = fparg0;
}
