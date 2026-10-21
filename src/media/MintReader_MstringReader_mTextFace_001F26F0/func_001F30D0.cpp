typedef int s32;
typedef unsigned char u8;
typedef float f32;

extern "C" s32 func_004A8368(char *s);

extern "C" s32 func_001F30D0(char **arg0, char *arg1, s32 arg2, f32 *arg3, f32 fparg0, f32 fparg1) {
    s32 neg;
    s32 lim;
    s32 i;
    s32 j;
    s32 n;
    s32 len = func_004A8368(*arg0);

    if (len <= 0) {
        return 0;
    }
    if (len >= arg2) {
        return 0;
    }
    if (fparg0 <= 0.0f) {
        return 0;
    }
    neg = -1;
    f32 q = fparg0 / (f32)len;
    lim = (s32)(fparg1 / q);
    i = 0;
    goto test;
    do {
        if ((*arg0)[i] == '-') {
            if ((*arg0)[i + 1] != 0) {
                neg = i;
            }
        }
        i++;
    test:
        ;
    } while (i < lim);

    if (neg < 0) {
        return 0;
    }
    n = neg + 1;
    for (j = 0; j < n; j++) {
        arg1[j] = ((u8 *)*arg0)[j];
    }
    arg1[neg + 1] = 0;
    *arg0 = *arg0 + neg + 1;
    *arg3 = (f32)n * q;
    return 1;
}
