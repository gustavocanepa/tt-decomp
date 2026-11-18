extern "C" float func_00464EF0(void *, float *, float *);
extern "C" void func_00473050();
extern "C" void func_004730A8();
extern "C" void func_00474CB8(int, int);
extern "C" void func_00475248();
extern "C" int func_00465C48(void *, int, float, float, float, float);
extern "C" int func_00466518(void *self, void *p, float num, float nf) {
    int n = (int)nf;
    float ax, ay;
    func_00473050();
    func_00475248();
    float r = func_00464EF0(p, &ax, &ay);
    func_004730A8();
    int ret = 0;
    if (!(r < -1.0f) && !(r > 1.0f)) {
        func_00474CB8(0, 0);
        ret = func_00465C48(self, 0, ax, ay, (float)n, num / (float)(n * n));
    }
    return ret;
}
