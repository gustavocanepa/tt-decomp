#include "types.h"

#define IPU_CMD 0x10002000

void func_004BB350(void);

s16 func_004CF9C0(void) {
    func_004BB350();
    *(volatile u32 *)IPU_CMD = 0x3C000000;
    __asm__ __volatile__("sync");
    func_004BB350();
    return (s16)(u16)(*(volatile u64 *)IPU_CMD & 0xFFFF);
}
