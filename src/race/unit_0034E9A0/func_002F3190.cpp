/* compiler: ee-gcc2.96-no-strict-aliasing */
struct B { char p[0xD0]; short n[2]; unsigned char kind[2]; char q[0xE0 - 0xD6]; float A[4]; float Bv[4]; };
struct Self { char p[4]; B b; };

extern "C" float func_002F3190(Self *self, short t, int idx) {
    B *b = &self->b;
    float r = 0.0f;
    short n = b->n[idx];
    if (t < n) {
        switch (b->kind[idx]) {
        case 0: {
            float d = t - n;
            r = b->A[idx] - b->Bv[idx] * d * d;
            break;
        }
        case 1: {
            float f = t;
            r = b->Bv[idx] * f * f;
            break;
        }
        case 2:
            r = b->A[idx] * (float)t / (float)n;
            break;
        }
    } else if (t < n * 3) {
        float d = t - n;
        r = b->A[idx] - b->Bv[idx] * d * d * 0.25f;
    }
    return r;
}
