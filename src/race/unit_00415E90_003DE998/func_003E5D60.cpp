/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004A6328(float, float *, float *);
extern "C" void func_003E5D60(float *arg0, float *arg1, float *arg2) {
    float t = *arg0;
    float buf[4];
    buf[0] = t;
    func_004A6328(t, arg1, arg2);
}
