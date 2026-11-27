/* compiler: ee-gcc2.9-991111 */
void func_005038D8(void);
void func_00503928(void);
void func_004FB1B0(unsigned int, unsigned int);

void func_004FB258(unsigned int start, unsigned int end) {
    unsigned int enabled;
    __asm__ volatile ("mfc0 %0,$12" : "=r" (enabled));
    enabled &= 0x10000;
    if (enabled)
        func_005038D8();
    func_004FB1B0(start & ~63U, end & ~63U);
    if (enabled)
        func_00503928();
}
