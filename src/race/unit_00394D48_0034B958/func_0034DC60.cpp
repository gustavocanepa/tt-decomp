#include "types.h"

struct Self { char pad[0x38]; f32 m38, m3C; };
extern f32 D_00584094;
extern "C" void func_0034DD00(void);

extern "C" void func_0034DC60(Self *self) {
    D_00584094 = 0x1.000000p+0f / (self->m3C * self->m38);
    func_0034DD00();
}
