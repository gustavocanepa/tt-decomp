/* compiler: ee-gcc2.9-991111 */
extern int D_005A4138;
extern char D_00791E00[];
extern unsigned int D_00791E40[];

int func_004FE530(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize,
                  void *end, void *arg);

unsigned int func_005061E8(void)
{
    if (D_005A4138 < 0)
        return 0;
    if (func_004FE530(D_00791E00, 7, 0, 0, 0, D_00791E40, 4, 0, 0) < 0)
        return 0xFFFFFFFF;
    return D_00791E40[0];
}
