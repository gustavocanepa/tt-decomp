/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_00464EF0(void *, float *, float *) throw();
extern "C" int func_00465C48(void *, int, float, float, float, float) throw();
extern "C" void func_0046F0F8(int);
extern "C" char D_00604CC0[];
extern "C" int func_00465FD0(void *self, float num, float size) {
    float ax, ay;
    float r = func_00464EF0(D_00604CC0, &ax, &ay);
    int ret = 0;
    if (!(r < -1.0f) && !(r > 1.0f)) {
        if (size < 2.0f) size = 2.0f;
        func_0046F0F8(5);
        int n = (int)size;
        ret = func_00465C48(self, 0, ax, ay, size, num / (float)(n * n));
    }
    return ret;
}
