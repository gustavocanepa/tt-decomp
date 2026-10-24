extern "C" int func_002FD8A0(char *a0, int a1, float *a2, float *a3, unsigned char *a4, unsigned char *a5);
extern "C" int func_00307270(char *arg0, float *arg1, float *arg2, int arg3, unsigned char *arg4, unsigned char *arg5) {
    int n;
    int i;
    n = arg3 & 0xFF;
    i = 0;
    if (n != 0) {
        do {
            arg1[i] = (float)arg4[i] * 0.2777777612209321f;
            arg2[i] = (float)arg5[i] * 0.2f * 0.017453290988f;
            i = i + 1;
        } while (i < n);
    }
    return func_002FD8A0(arg0, n, arg1, arg2, 0, 0);
}
