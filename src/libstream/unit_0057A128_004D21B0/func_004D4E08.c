/* compiler: ee-gcc2.9-991111 */
int func_004D9E48(void *);
int func_004D9E68(int);
int func_004D4E08(void) {
    int next = func_004D9E68(func_004D9E48(__builtin_return_address(0)));
    int old;
    __asm__ volatile ("daddu %0, $28, $0" : "=r"(old));
    __asm__ volatile ("daddu $28, %0, $0" : : "r"(next) : "$28");
    return old;
}
