/* compiler: ee-gcc2.9-991111 */
extern int *D_00782AE8;
extern int *D_00782AEC;
extern int *D_00782AF0;
extern int D_005A0BF8;

void func_004FA850(int a);

void func_004DBBC0(unsigned int addr) {
    int *p = (int *)(addr | 0x20000000);
    if (D_00782AE8 != 0) {
        *D_00782AE8 = p[0];
    }
    if (D_00782AEC != 0) {
        *D_00782AEC = p[1];
    }
    if (D_00782AF0 != 0) {
        *D_00782AF0 = p[36];
    }
    func_004FA850(D_005A0BF8);
}
