/* compiler: ee-gcc2.9-991111 */
extern int D_005A23C0;
extern int D_005A1F80[];
extern int D_005A2928, D_005A292C, D_005A2930;
extern int D_005A0DAC;
extern char D_005A2900[];
int func_004DF890(int);
void func_004FA840(int);
int func_004FDAF8(void *, int);
int func_004FE530(void *, int, int, void *, int, void *, int, void *, void *);
int func_004E01B8(int arg0) {
    int r;
    int *p = &D_005A23C0;
    if (func_004DF890(0x22) == 0) return 0;
    *p = arg0;
    func_004FDAF8(p, 4);
    if (func_004FE530(D_005A2900, D_005A2928, 0, p, D_005A292C, D_005A1F80, D_005A2930, 0, 0) < 0) {
        func_004FA840(D_005A0DAC);
        return 0;
    }
    r = *(int *)((unsigned int)D_005A1F80 | 0x20000000);
    func_004FA840(D_005A0DAC);
    return r;
}
