/* compiler: ee-gcc2.9-991111 */
extern int D_005A0D90;
extern int D_005A0DB4;
extern char D_005A1F50[];
extern char D_00614C50[];
void func_004FB898(int);
void func_004FD2D0(const char *, ...);
int func_004FE730(void *);

int func_004DF780(int mode)
{
    if (mode == 0) {
        if (D_005A0D90 > 0)
            func_004FD2D0(D_00614C50);
        while (D_005A0DB4 != 0 || func_004FE730(D_005A1F50) != 0)
            func_004FB898(0xFA0);
        return 0;
    }
    if (D_005A0DB4 != 0 || func_004FE730(D_005A1F50) != 0)
        return 1;
    return 0;
}
