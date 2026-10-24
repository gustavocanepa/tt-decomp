/* compiler: ee-gcc2.9-991111 */
typedef struct { char pad[0x24]; int f24; } Dev;
extern volatile int D_005A0DAC;
extern int D_005A0D90, D_005A0DC0, D_005A0DD0;
extern int D_0078A8D0, D_005A1F80;
extern Dev D_0078A890;
extern char D_00614CE0[], D_00614CF8[], D_00614D18[];
extern void func_004DEF98(void);
extern int func_004DF820(int);
extern void func_004FA840(int);
extern int func_004FA870(int);
extern void func_004FD2D0(const char *, ...);
extern void func_004FDAF8(void *, int);
extern void func_004FDBA8(int);
extern int func_004FE350(void *, int, int);
extern int func_004FE530(void *, int, int, void *, int, void *, int, void *, void *);
extern int func_005038D8(void);
extern int func_00503928(void);
int func_004DFD80(int a) {
    int i, intr, result;
    if (D_005A0D90 > 0) func_004FD2D0(D_00614CE0);
    intr = func_005038D8();
    D_005A0DC0 = 1;
    if (intr) func_00503928();
    func_004DEF98();
    if (D_005A0DAC != func_004FA870(D_005A0DAC)) return 6;
    if (func_004DF820(1)) {
        func_004FA840(D_005A0DAC);
        return a != 8 ? 6 : -1;
    }
    {
        func_004FDBA8(0);
        if (D_005A0DD0 < 0) {
            for (;;) {
                if (func_004FE350(&D_0078A890, 0x8000059A, 0) < 0) {
                    if (D_005A0D90 > 0) func_004FD2D0(D_00614CF8);
                    for (i = 0x100000; i != -1; i--) ;
                    continue;
                }
                if (D_0078A890.f24 != 0) { D_005A0DD0 = 0; break; }
                for (i = 0x100000; i != -1; i--) ;
            }
        }
        D_0078A8D0 = a;
        func_004FDAF8(&D_0078A8D0, 4);
        if (func_004FE530(&D_0078A890, 0, 0, &D_0078A8D0, 4, &D_005A1F80, 4, 0, 0) < 0) {
            func_004FA840(D_005A0DAC);
            return a != 8 ? 6 : -1;
        }
        {
            if (D_005A0D90 > 0) func_004FD2D0(D_00614D18);
            result = *(int *)((unsigned int)&D_005A1F80 | 0x20000000);
            func_004FA840(D_005A0DAC);
            return result;
        }
    }
}
