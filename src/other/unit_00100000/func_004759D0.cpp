struct Regs {
    char pad[0xC20];
    int value;
};

int func_004759D0(void) {
    volatile Regs *ptr = (volatile Regs *)0x70002000;
    return ptr->value;
}
