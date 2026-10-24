/* compiler: ee-gcc2.9-991111 */
void func_004FAB90(volatile int *,long *);
int func_005038D8(void);
int func_00503928(void);
long func_004FAD40(void) {
    struct { volatile int flag; int pad; volatile long value; } local;
    int intr;
    local.flag=0;
    func_004FAB90(&local.flag,(long *)((unsigned int)&local | 8));
    intr=func_005038D8();
    *(volatile int *)0x1000F000=4;
    __asm__ volatile("sync");
    if(intr) func_00503928();
    while(!(*(volatile int *)0x1000F000&4) && local.flag==0) {}
    intr=func_005038D8();
    *(volatile int *)0x1000F000=4;
    __asm__ volatile("sync");
    if(intr) func_00503928();
    return local.value;
}
