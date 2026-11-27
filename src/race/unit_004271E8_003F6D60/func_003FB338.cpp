#include "types.h"

struct __attribute__((aligned(8))) S { char pad[0x8]; s64 unk8; };

extern "C" void func_003FB338(S *arg0) {
    arg0->unk8 = arg0->unk8 | 1;
}
