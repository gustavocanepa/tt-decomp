/* compiler: ee-gcc2.9-991111 */
struct Callback {
    void (*fn)(void *);
    void *arg;
};

extern void *D_0078F4C0;

void func_004FF428(void *unused, struct Callback *cb) {
    if (cb->fn) {
        void *saved;
        __asm__ volatile("move %0, $gp\n\tlw $gp, %1" : "=r"(saved) : "m"(D_0078F4C0));
        cb->fn(cb->arg);
        __asm__ volatile("move $gp, %0" : : "r"(saved));
    }
    __asm__ volatile("sync\n\tei");
}
