/* compiler: ee-gcc2.9-991111 */
int func_004FD2D0(const char *fmt, ...);
void func_004FB898(int usec);
int func_004FE730(void *sema);
extern int D_005A0D90;
extern char D_00614C60[];
extern char D_005A2900[];

int func_004DF820(int nowait)
{
    if (nowait == 0) {
        if (D_005A0D90 > 0)
            func_004FD2D0(D_00614C60);
        while (func_004FE730(D_005A2900))
            func_004FB898(4000);
        return 0;
    }
    return func_004FE730(D_005A2900);
}
