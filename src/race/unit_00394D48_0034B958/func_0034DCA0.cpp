#include "types.h"

struct Obj00397E38 {
    char pad[0x38];
    f32 unk38;
};

extern "C" f32 D_00584094;
extern "C" void func_0034DD00(void);

extern "C" void func_0034DCA0(struct Obj00397E38 *arg0) {
    D_00584094 = 1.0f / arg0->unk38;
    func_0034DD00();
}
