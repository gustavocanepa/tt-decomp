/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Parses a stream header field by field with the bit reader func_004CC568 (4x4, 2, 2, 1, 1 bits
   into globals, three flags kept for D_005A0838, an optional block behind a 1-bit flag). Fields
   stored through get() take their address in a saved register before the call, as the original. */
extern "C" int func_004CC568(int n);
extern int D_005A0818[4];
extern int D_005A0828;
extern int D_005A082C;
extern int D_005A0830;
extern int D_005A0838[9];
static inline void get(int *dst, int n) { *dst = func_004CC568(n); }
extern "C" void func_004CD0D8(void) {
    D_005A0818[0] = func_004CC568(4);
    D_005A0818[1] = func_004CC568(4);
    D_005A0818[2] = func_004CC568(4);
    D_005A0818[3] = func_004CC568(4);
    int a = func_004CC568(2);
    get(&D_005A0828, 2);
    get(&D_005A082C, 1);
    get(&D_005A0830, 1);
    func_004CC568(1);
    int b = func_004CC568(1);
    int c = func_004CC568(1);
    int d = func_004CC568(1);
    func_004CC568(1);
    func_004CC568(1);
    func_004CC568(1);
    if (func_004CC568(1)) {
        func_004CC568(1);
        func_004CC568(3);
        func_004CC568(1);
        func_004CC568(7);
        func_004CC568(8);
    }
    D_005A0838[6] = a;
    D_005A0838[7] = c;
    D_005A0838[8] = b;
    D_005A0838[5] = d;
}
