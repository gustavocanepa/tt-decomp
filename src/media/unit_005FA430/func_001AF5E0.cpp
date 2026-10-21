#include "types.h"

struct Obj005FD900 {
    char pad[0x140E0];
    f32 unk1E660;
    f32 unk1E664;
};

extern "C" void func_001AF5E0(struct Obj005FD900 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk1E660 = fparg0;
    arg0->unk1E664 = fparg1;
}
