struct Regs {
    char pad[0xECC];
    int value;
};

int func_00478C88(void) {
    volatile Regs *ptr = (volatile Regs *)0x70002000;
    return ptr->value;
}
