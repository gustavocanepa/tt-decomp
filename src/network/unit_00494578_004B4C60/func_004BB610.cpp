/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Hook { int (*fn)(void *, int); void *arg; };
extern struct Hook D_005983E0;
static inline u32 fifo_count() { return ((*(volatile u32 *)0x10002020) >> 8) & 15; }
extern "C" void func_004BB610(void) {
    struct Hook *hook = &D_005983E0;
    while (fifo_count() == 0) {
        hook->fn(hook->arg, 0);
    }
}
