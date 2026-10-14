/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
extern "C" char *func_004391C8(int *, unsigned int);
extern "C" float func_00439488(int *, float);
extern "C" int func_004A64A8(char *, unsigned int, const char *, ...);
extern int D_005865D0[];
extern char D_005F9668[];
extern char D_005F9670[];

extern "C" void func_003F5C20(char *buf, unsigned int size, float x) {
    char *name = func_004391C8(D_005865D0, size);
    if (x == 0.0f) {
        func_004A64A8(buf, size, D_005F9668, name);
        return;
    }
    float v = func_00439488(D_005865D0, x);
    int n = (int)(v * 100.0f);
    int r = n % 100;
    int q = n / 100;
    func_004A64A8(buf, size, D_005F9670, q, r, name);
}
