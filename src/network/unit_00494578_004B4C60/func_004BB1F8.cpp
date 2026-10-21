/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
extern u128 D_00598370[5];
#define CTRL (*(volatile int *)0x10002010)
#define FIFO (*(volatile u128 *)0x10007010)
extern "C" void func_004BB1F8(void) {
 while (CTRL < 0) {}
 u128 v = D_00598370[4];
 FIFO = v;
 __asm__ volatile("sync" ::: "memory");
 FIFO = v;
 __asm__ volatile("sync" ::: "memory");
 FIFO = v;
 __asm__ volatile("sync" ::: "memory");
 FIFO = v;
 __asm__ volatile("sync" ::: "memory");
 while (CTRL < 0) {}
 *(volatile int *)0x10002000 = 0x58000000;
 __asm__ volatile("sync" ::: "memory");
 while (CTRL < 0) {}
}
