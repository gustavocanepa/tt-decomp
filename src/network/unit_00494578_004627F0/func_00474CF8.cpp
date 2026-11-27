/* compiler: ee-gcc2.96-no-strict-aliasing */

extern "C" int func_00475098(float *);

extern "C" long func_00474CF8(float *a, float *b)
{
    int i;

    for (i = 0; i < 6; i++) {
        int c0 = func_00475098(a);
        int c1 = func_00475098(b);

        if ((c0 & c1) != 0 || (c0 | c1) == 0) return c0 | c1;
        if (((c0 | c1) >> i) & 1) {
            float p, q, t;
            int k;

            if (i & 1) {
                p = a[i >> 1] + a[3];
                q = b[i >> 1] + b[3];
            } else {
                p = a[i >> 1] - a[3];
                q = b[i >> 1] - b[3];
            }
            t = 1.0f / (p - q);
            if ((c0 >> i) & 1) {
                for (k = 0; k < 4; k++)
                    a[k] = (b[k] * p - a[k] * q) * t;
            } else {
                for (k = 0; k < 4; k++)
                    b[k] = (b[k] * p - a[k] * q) * t;
            }
        }
    }
    return 0;
}
