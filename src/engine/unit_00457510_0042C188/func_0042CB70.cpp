/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" char D_0076A028[];
extern "C" char *D_0076A01C;
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" int func_0042C9C0(int, int, float, int) throw();
extern "C" void func_004C6A78(char *, int, float, float);
extern "C" void func_0042CB70(int a, float x, int b, float y, int c) {
    func_004A4D68(D_0076A028);
    if (func_0042C9C0(a, b, y, c)) {
        func_004C6A78(D_0076A01C, 0, 1.0f, x);
    }
    func_004A4DD8(D_0076A028);
}
