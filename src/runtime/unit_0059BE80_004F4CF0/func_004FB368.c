/* compiler: ee-gcc2.9-991111 */
int func_005038D8(void);
void func_00503928(void);
int func_004FA560(void *arg);

int func_004FB368(void *arg)
{
    int status;
    int ret;

    __asm__ volatile("mfc0 %0, $12" : "=r"(status));
    status &= 0x10000;
    if (status)
        func_005038D8();
    ret = func_004FA560(arg);
    __asm__ volatile("sync.l");
    if (status)
        func_00503928();
    return ret;
}
