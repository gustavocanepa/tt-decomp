/* compiler: ee-gcc2.9-991111 */
extern int D_005A0DAC;
extern char D_005A2900[];
extern int D_005A1F80[];

int func_004DF890(int a);
void func_004FA840(int sema);
int func_004FE530(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *arg);

int func_004E11F8(void)
{
    int r;
    if (func_004DF890(1) == 0)
        return -1;
    if (func_004FE530(D_005A2900, 3, 0, 0, 0, D_005A1F80, 4, 0, 0) < 0) {
        func_004FA840(D_005A0DAC);
        return -1;
    }
    r = *(int *)((unsigned int)D_005A1F80 | 0x20000000);
    func_004FA840(D_005A0DAC);
    return r;
}
