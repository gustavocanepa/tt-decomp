typedef int s32;

struct Regs {
    char pad[0x21C];
    s32 value;
};

void func_0046AC38(s32 arg0) {
    volatile Regs *ptr = (volatile Regs *)0x70002000;
    ptr->value = arg0;
}
