/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_002E20C0(void *self, int n, float *a, float *b) {
    int k;
    if (n >= 4) {
        int count = n * 3 - 9;
        float *dst = a + n * 3;
        float *src = dst - 3;
        float z = dst[-1];
        float y = dst[-2];
        float x = *src;
        for (k = 0; k < count; k++) {
            --src;
            --dst;
            *dst = *src;
        }
        a[6] = x;
        a[7] = y;
        a[8] = z;
        dst = b + n * 2;
        src = dst - 2;
        y = dst[-1];
        x = *src;
        for (k = 0; k < n * 2 - 6; k++) {
            --src;
            --dst;
            *dst = *src;
        }
        b[4] = x;
        b[5] = y;
    }
}
