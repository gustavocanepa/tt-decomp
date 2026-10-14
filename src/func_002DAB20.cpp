extern "C" char D_005865D0[];
extern "C" char D_005F28E8[];

extern "C" void func_0038FAA0(char *out, int unused, int value);
extern "C" float func_004397D8(int *p, float x);
extern "C" void func_004A6500(int arg0, int arg1, ...);

extern "C" void func_002DAB20(char *arg0, int arg1, float fparg0, float fparg1) {
    int value;
    float q;

    if (fparg0 <= 0.0f) {
        *arg0 = 0;
        return;
    }
    if (fparg1 != 0.0f && fparg1 <= fparg0) {
        q = fparg0 / fparg1;
        func_0038FAA0(arg0, arg1, (int)q);
        return;
    }
    value = (int)(func_004397D8((int *)D_005865D0, fparg0) + 0.5f);
    func_004A6500((int)arg0, (int)D_005F28E8, value);
}
