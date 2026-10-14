typedef int s32;
extern "C" char D_0076A028[];
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_0042CAF8(void *s, int a, float f, int b);
extern "C" int func_0042CC18(void *s, int a, float f, int b);
extern "C" void func_0042CC68(void *s, int a, int b, float f) {
    int r;
    func_004A4D68(D_0076A028);
    r = func_0042CC18(s, a, f, b);
    if (r >= 0) {
        func_0042CAF8((void *)r, a, f, b);
    }
    func_004A4DD8(D_0076A028);
}
