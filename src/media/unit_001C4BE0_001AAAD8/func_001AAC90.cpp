struct Local { float a; int b; float c; int d; };
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_0047525C(void *p);
extern "C" void func_00475850(void *p, Local *l);
extern "C" float func_004A5C50(float x);
extern "C" float func_004A5DE0(float x);

extern "C" void func_001AAC90(void *arg0, void *arg1, float fparg0, float fparg1) {
    Local L;
    float x = fparg1 * 6.2831853f;
    float t20 = func_004A5DE0(fparg0 * 0.017453292f);
    float r;
    L.a = 1.0f;
    L.b = 0;
    r = func_004A5C50(x * 0.5f);
    t20 = t20 * r;
    L.c = t20;
    L.d = 0;
    func_00473050();
    func_0047525C(arg1);
    func_00475850(arg0, &L);
    func_004730A8();
}
