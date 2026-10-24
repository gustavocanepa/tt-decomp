/* compiler: ee-gcc2.9-991111 */
typedef struct { char pad[0x24]; int f24; } Dev;
extern volatile int D_005A0DA8;
extern int D_005A0D90;
extern int D_005A0D9C;
extern int D_005A0DBC;
extern Dev D_005A1F50;
extern void func_004DEF98(void);
extern int func_004DF780(int);
extern void func_004FA840(int);
extern int func_004FA870(int);
extern void func_004FD2D0(const char *, ...);
extern void func_004FDBA8(int);
extern int func_004FE350(void *, int, int);
extern char D_00614C10[];
extern char D_00614C38[];

int func_004DF590(int a) {
    int i;
    func_004DEF98();
    if (D_005A0DA8 != func_004FA870(D_005A0DA8)) {
        if (D_005A0D90 > 0) func_004FD2D0(D_00614C10, a, D_005A0D9C);
        return 0;
    }
    D_005A0D9C = a;
    if (func_004DF780(1)) {
        func_004FA840(D_005A0DA8);
        return 0;
    }
    func_004FDBA8(0);
    if (D_005A0DBC < 0) {
        for (;;) {
            if (func_004FE350(&D_005A1F50, 0x80000595, 0) < 0) {
                if (D_005A0D90 > 0) func_004FD2D0(D_00614C38);
                for (i = 0x100000; i != -1; i--) ;
                continue;
            }
            if (D_005A1F50.f24 != 0) break;
            for (i = 0x100000; i != -1; i--) ;
        }
        D_005A0DBC = 0;
    }
    return 1;
}
