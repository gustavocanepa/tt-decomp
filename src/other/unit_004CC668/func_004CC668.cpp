/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;

extern "C" void func_004BB350(void);

extern "C" void func_004CC668(u32 arg) {
    func_004BB350();
    *(volatile u32 *)0x10002000 = (arg & 0x7F) | 0x40000000;
    __asm__ volatile("sync");
}
