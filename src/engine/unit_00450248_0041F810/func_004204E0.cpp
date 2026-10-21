/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Box {
    char pad0[1];
    unsigned char kind;
    char pad2[2];
    float *corners;
    float radius;
    float center[3];
};

static inline float sqrt_s(float x) {
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_004204E0(Box *b, float *a, float *c) {
    if (b->kind == 8) {
        float *q = b->corners;
        if (q) {
            float *p = q;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    for (int k = 0; k < 2; k++) {
                        *p++ = i ? a[0] : c[0];
                        *p++ = j ? a[1] : c[1];
                        *p++ = k ? a[2] : c[2];
                    }
            float sum = 0.0f;
            for (int n = 0; n < 3; n++) {
                float m = (a[n] + c[n]) * 0.5f;
                b->center[n] = m;
                float d = c[n] - m;
                sum += d * d;
            }
            b->radius = sqrt_s(sum);
        }
    }
}
