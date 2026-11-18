/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004757FC(void);
extern "C" void func_00475850(void *, void *);
extern char D_005FFEC0[];

extern "C" int func_0041D340(int flag, float a, float b) {
    float v[3];
    if (b < 0.0f)
        return 1;
    func_00473050();
    func_004757FC();
    func_00475850(v, D_005FFEC0);
    func_004730A8();
    float nb = -b;
    if (flag)
        v[0] = -v[0];
    float t = (a / b) * v[0] + a;
    if (nb < v[0]) {
        return t * t < v[1] * v[1] + v[2] * v[2];
    }
    return 1;
}
