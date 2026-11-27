/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_00776B88;
extern int D_00776B8C;
#define CTRL (*(volatile int *)0x10002010)
extern "C" void func_004BB2B8(int x, int y) {
    D_00776B88 = x;
    D_00776B8C = y;
    while (CTRL < 0) {}
    unsigned int low = D_00776B88 & 0x1FF;
    unsigned int high = (D_00776B8C << 16) & 0x01FF0000;
    unsigned int command = 0x90000000;
    command |= low;
    command |= high;
    *(volatile int *)0x10002000 = command;
    __asm__ volatile("sync" ::: "memory");
    while (CTRL < 0) {}
}
