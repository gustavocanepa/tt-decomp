/* compiler: ee-gcc2.9-991111 */
extern int func_005038D8(void);
extern int func_00503928(void);
void func_004FACB0(void) {
    int intr;
    intr=func_005038D8();
    *(volatile int *)0x1000F000=4;
    __asm__ volatile("sync");
    if(intr) func_00503928();
    while(!(*(volatile int *)0x1000F000&4)) {}
    intr=func_005038D8();
    *(volatile int *)0x1000F000=4;
    __asm__ volatile("sync");
    if(intr) func_00503928();
}
