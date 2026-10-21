#include "types.h"

extern "C" void func_001E2A20(void *);
extern "C" void func_001E2BF8(void *, s32);
extern "C" void func_001E2CB0(void *);

extern "C" void func_001E2CF8(void *self, s32 a) {
    func_001E2A20(self);
    func_001E2BF8(self, a);
    func_001E2CB0(self);
}
