/* compiler: ee-gcc2.9-991111 */
struct SemaParam { int current, max, init, wait; unsigned int attr; const char *option; };
extern volatile int D_005A0DA8, D_005A0DAC, D_005A0DB0, D_005A0DA0, D_005A0DB4;
extern char D_00614B58[], D_00614B68[], D_00614B78[], D_00614B88[];
extern int func_004FA820(void *);
void func_004DEF98(void) {
    struct SemaParam p;
    if (D_005A0DA8 == -1 || D_005A0DAC == -1 || D_005A0DB0 == -1) {
        p.init = 1;
        p.max = 1;
        p.option = D_00614B58;
        D_005A0DA8 = func_004FA820(&p);
        p.option = D_00614B68;
        D_005A0DAC = func_004FA820(&p);
        p.option = D_00614B78;
        D_005A0DB0 = func_004FA820(&p);
        p.option = D_00614B88;
        p.init = 0;
        D_005A0DA0 = func_004FA820(&p);
        D_005A0DB4 = 0;
    }
}
