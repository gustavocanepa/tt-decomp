/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
extern u128 D_00598370[4];
#define CTRL (*(volatile int *)0x10002010)
#define FIFO (*(volatile u128 *)0x10007010)
extern "C" void func_004BB130(void) {
 while (CTRL < 0) {}
 FIFO = D_00598370[0];
 __asm__ volatile("sync" ::: "memory");
 FIFO = D_00598370[1];
 __asm__ volatile("sync" ::: "memory");
 FIFO = D_00598370[2];
 __asm__ volatile("sync" ::: "memory");
 FIFO = D_00598370[3];
 __asm__ volatile("sync" ::: "memory");
 while (CTRL < 0) {}
 *(volatile int *)0x10002000 = 0x50000000;
 __asm__ volatile("sync" ::: "memory");
 while (CTRL < 0) {}
}
