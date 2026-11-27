#include "types.h"

extern "C" void func_005740B8(void *, void *, s32);
extern "C" void func_00574128(void *, void *, s32);

extern "C" void func_004C6C80(char *self) {
    func_005740B8(self, self, 12);
    func_00574128(self, self + 0x540, 2);
}
