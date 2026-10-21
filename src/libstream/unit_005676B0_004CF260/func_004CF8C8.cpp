typedef unsigned long u64;
extern "C" void func_004BB350(void);
extern "C" int func_004CC5A8(int);
extern "C" void func_004CC668(unsigned);
extern "C" int func_004CF8C8(void) {
    int total = 0;
    int value;
    while ((value = func_004CC5A8(11)) < 24) {
        if (value != 15) total += 33;
        func_004CC668(11);
    }
    if (value >= 1024) {
        func_004CC668(1);
        return total + 1;
    }
    func_004BB350();
    *(volatile unsigned *)0x10002000 = 0x30000000;
    __asm__ volatile("sync");
    func_004BB350();
    return total + (int)(*(volatile u64 *)0x10002000 & 0xffff);
}
