/* compiler: ee-gcc2.9-991111 */
extern int D_005A4138;
extern char D_00791E00[];
extern int D_00791E80[];
extern int D_00791E40[];

int func_004FE530(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *arg);

int func_00505F00(int a0, int a1, int a2)
{
    if (D_005A4138 < 0)
        return 0;
    D_00791E80[0] = a1;
    D_00791E80[1] = a0;
    D_00791E80[2] = a2;
    if (func_004FE530(D_00791E00, 4, 0, D_00791E80, 0xC, D_00791E40, 4, 0, 0) < 0)
        return 0;
    return D_00791E40[0];
}
