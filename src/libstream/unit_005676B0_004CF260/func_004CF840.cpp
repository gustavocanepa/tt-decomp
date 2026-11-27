#include "types.h"
extern "C" void func_004BB350(void);
extern "C" int func_004CF840(int mode) {
    func_004BB350();
    u32 temp = *(volatile u32 *)0x10002010;
    temp = (temp & 0xF8FFFFFF) | ((mode << 24) & 0x07000000);
    *(volatile u32 *)0x10002010 = temp;
    __asm__ volatile("sync");
    func_004BB350();
    temp = 0x34000000;
    *(volatile u32 *)0x10002000 = temp;
    __asm__ volatile("sync");
    func_004BB350();
    return (int)(*(volatile u64 *)0x10002000 & 0xFFFF);
}
