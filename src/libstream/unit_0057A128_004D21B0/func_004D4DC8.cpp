extern "C" int func_004D4DC8(int value) {
    int old;
    __asm__ volatile ("daddu %0, $28, $0" : "=r"(old));
    __asm__ volatile ("daddu $28, %0, $0" : : "r"(value) : "$28");
    return old;
}
