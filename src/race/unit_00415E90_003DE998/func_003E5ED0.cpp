/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float *func_003E5C78(float *, float) throw();
extern "C" float func_004A5C50(float) throw();
extern "C" float func_003E5ED0(float *a) {
    float first[4];
    float second[4];
    float spare[4];
    float tmp[4];
    float *p = second;
    float x = *a;
    first[0] = x;
    float y = *func_003E5C78(tmp, x);
    p[0] = y;
    return func_004A5C50(y);
}
