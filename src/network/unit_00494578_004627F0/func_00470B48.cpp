#include "types.h"

struct Regs {
    char pad[0x228];
    s32 value;
};

void func_00470B48(s32 arg0) {
    volatile Regs *ptr = (volatile Regs *)0x70002000;
    ptr->value = arg0;
}
