/* compiler: ee-gcc2.9-991111 */
extern int D_005A0DAC;
extern int D_005A0D90;
extern int D_00655F20;
extern char D_005A2900[];
extern int D_005A1F80[];
extern char D_00614E48[];

int func_004DF890(int a);
void func_004FA840(int sema);
int func_004FD2D0(const char *fmt, ...);
int func_004FE530(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *arg);

int func_004E1350(void)
{
    int r;
    if (func_004DF890(2) == 0)
        return -1;
    if (func_004FE530(D_005A2900, 12, 0, 0, 0, D_005A1F80, 4, 0, 0) < 0) {
        func_004FA840(D_005A0DAC);
        return -1;
    }
    r = *(int *)((unsigned int)D_005A1F80 | 0x20000000);
    func_004FA840(D_005A0DAC);
    if (D_005A0D90 >= 2)
        func_004FD2D0(D_00614E48);
    return r;
}
