/* compiler: ee-gcc2.9-991111 */
extern int func_005038D8(void);
extern void func_00503928(void);
extern void func_005041C8(unsigned int mode);

int func_005044B8(void) {
    int intr = func_005038D8();
    unsigned int mode = *(volatile unsigned int *)0x10001010;
    if ((mode & 0x80) == 0) {
        if (intr)
            func_00503928();
        return 0;
    }
    func_005041C8(mode & ~0xC80);
    if (intr)
        func_00503928();
    return 1;
}
