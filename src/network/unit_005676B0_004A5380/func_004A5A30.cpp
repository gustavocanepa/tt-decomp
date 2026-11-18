#include "types.h"
extern "C" {
s64 func_00504A80(void);
void __udivdi3(s64 a, int b);
}
extern "C" void func_004A5A30(void) {
    __udivdi3(func_00504A80() * 0x7D, 0x4800);
}
