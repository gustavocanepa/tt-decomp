/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_00317438(float) throw();
extern "C" float func_00317630(float, float) throw();
extern "C" float func_004EE530(float);
extern "C" void func_00317888(float *a, float *out){
    float t[12];
    float *p = &t[8];
    float *q = &t[9];
    t[0] = a[0]; t[1] = a[4]; t[2] = a[8];
    t[4] = a[1]; t[5] = a[5]; t[6] = a[9];
    *p = a[2]; *q = a[6]; t[10] = a[10];
    out[0] = func_00317438(func_00317630(*p, t[10]) - 90.0f);
    float r = func_00317438(func_004EE530(*q) * 180.0f / 0x1.921fb4p+1f);
    *(int *)&out[2] = 0;
    out[1] = r;
}
