/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { char p[0xE4]; float f[2]; };
extern "C" float func_002F3190(Self *, int, int) throw();

extern "C" float func_002F32C0(Self *self, short a, short b, float *out) {
    short v[2];
    float sum = 0.0f;
    float zero = sum;
    v[0] = a;
    v[1] = b;
    out[0] = 0.0f;
    out[1] = 0.0f;
    for (int i = 0; i < 2; i++) {
        if (self->f[i] != zero) {
            float t = func_002F3190(self, v[i], i);
            sum += t;
            out[i] = t;
        }
    }
    return sum + 1.0f;
}
