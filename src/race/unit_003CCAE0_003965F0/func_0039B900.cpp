#include "types.h"

struct Self { char pad[0x968C]; s32 m9674; s32 m9678; };
extern "C" void func_0039B7F8(Self *, s32, s32, s32);

extern "C" void func_0039B900(Self *self, s32 a, s32 b) {
    self->m9678 = -1;
    self->m9674 = 0;
    func_0039B7F8(self, a, b, -1);
}
