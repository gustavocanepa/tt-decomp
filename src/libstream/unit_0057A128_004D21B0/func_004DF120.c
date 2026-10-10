/* compiler: ee-gcc2.9-991111 */
extern int D_005A0DC8;
extern int D_0078A648;
extern void *D_0078A64C;
extern int D_0078A650;
extern void func_004DF1F8(void);
extern int func_005038D8(void);
extern void func_00503928(void);

int func_004DF120(int a, int b)
{
    int old;
    int state;

    if (D_005A0DC8 < 0)
        func_004DF1F8();
    state = func_005038D8();
    old = D_0078A648;
    D_0078A650 = b;
    D_0078A648 = a;
    __asm__ volatile("sw $gp, %0" : "=m"(D_0078A64C));
    if (state)
        func_00503928();
    return old;
}
