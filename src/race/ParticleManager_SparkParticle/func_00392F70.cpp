extern "C" void *func_00393570(void *owner);
extern "C" void func_00392200(void *p, int a, int b, float x, float y, int c, float z, int d);

extern "C" void func_00392F70(void *owner, int a, int b, float x, float y, int c, float z, int d) {
    void *p = func_00393570(owner);
    if (p)
        func_00392200(p, a, b, x, y, c, z, d);
}
