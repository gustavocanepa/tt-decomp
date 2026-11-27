struct S {
    int mode;
    float a;
    float b;
    float c;
};

static inline int clamp1(int v) {
    if (v <= 0) return 0;
    if (v >= 0x65) return 0x64;
    return v;
}

static inline int clamp0(int v) {
    if (v < 0) return 0;
    if (v >= 0x65) return 0x64;
    return v;
}

static inline float fsqrt(float x) {
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_002FFCE8(S *s, int mode, int pct) {
    s->mode = mode;
    switch (mode) {
    case 1: {
        if (pct <= 0) {
            pct = 0;
        } else if (pct >= 0x65) {
            pct = 0x64;
        }
        int x = pct;
        float f = (float)x * 0.01f;
        s->c = f;
        if (f < 0.001f) s->c = 0.001f;
        float c = s->c;
        float t = -(1.0f - c) / (2.0f * c);
        s->a = t;
        s->b = -c * t * t;
        break;
    }
    case 2: {
        if (pct < 0) {
            pct = 0;
        } else if (pct >= 0x65) {
            pct = 0x64;
        }
        int x = pct;
        float f = (float)(0x64 - x) * 0.01f + 1.0f;
        float g = f * f;
        s->c = f;
        float h = g - 1.0f;
        float t = -(h * h) / (g * 4.0f);
        float q = fsqrt(-t);
        s->a = t;
        s->b = -f * q;
        break;
    }
    case 3: {
        if (pct <= 0) {
            pct = 0;
        } else if (pct >= 0x65) {
            pct = 0x64;
        }
        int x = pct;
        s->a = 0.0f;
        float f = (float)x * 0.01f;
        s->c = f;
        s->b = 1.0f - f;
        break;
    }
    default:
        s->a = 0.0f;
        s->b = 0.0f;
        s->c = 0.0f;
        break;
    }
}
