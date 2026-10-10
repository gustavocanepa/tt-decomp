/* compiler: ee-gcc2.9-991111 */
extern int D_005A4138;
extern char D_00791E00[];
extern int D_00791E80[];
extern int D_00791E40[];

int func_004FE530(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *arg);

unsigned int func_00506258(int value)
{
    if (D_005A4138 < 0)
        return 0;
    D_00791E80[0] = value;
    if (func_004FE530(D_00791E00, 8, 0, D_00791E80, 4, D_00791E40, 4, 0, 0) < 0)
        return 0xFFFFFFFFU;
    return D_00791E40[0];
}
