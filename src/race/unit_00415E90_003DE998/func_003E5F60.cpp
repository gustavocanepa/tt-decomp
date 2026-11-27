/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float *func_003E5C78(float *, float) throw();
extern "C" void func_004A6328(float,float *,float *);
extern "C" void func_003E5F60(float *a,float *s,float *c) {
    float first[4];
    float second[4];
    float spare[4];
    float tmp[4];
    float *p = second;
    float x = *a;
    first[0] = x;
    float y = *func_003E5C78(tmp,x);
    p[0] = y;
    func_004A6328(y,s,c);
}
