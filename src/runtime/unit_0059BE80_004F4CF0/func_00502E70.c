/* compiler: ee-gcc2.9-991111 */
extern char D_0078F700[];
extern int D_0078F500[];

int func_004FE530(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *arg);
int func_00502898(void);
int func_00502998(void);

int func_00502E70(int value)
{
    if (func_00502898() < 0)
        return -0x10000;
    if (func_00502998() != 0)
        return -0x10004;
    D_0078F500[0] = value;
    if (func_004FE530(D_0078F700, 8, 0, D_0078F500, 4, D_0078F500, 4, 0, 0) < 0)
        return -0x10001;
    return D_0078F500[0];
}
