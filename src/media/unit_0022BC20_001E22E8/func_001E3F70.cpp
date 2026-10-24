extern "C" int func_001E3F70(const volatile float *a, const volatile float *b) {
    int r=0;
    if (__builtin_fabsf(a[0]-b[0])>0.1f) goto done;
    if (__builtin_fabsf(a[1]-b[1])>0.1f) goto done;
    if (__builtin_fabsf(a[2]-b[2])>0.1f) goto done;
    if (__builtin_fabsf(a[3]-b[3])>0.1f) goto done;
    r=1;
 done: return r;
}
