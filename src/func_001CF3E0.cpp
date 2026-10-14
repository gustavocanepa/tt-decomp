/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct T {
    f32 a[3];
    f32 b[3];
    f32 d;
    f32 e[2];
    f32 tail[3];
};

extern "C" T func_001CF3E0(const T *p, const T *q, f32 t) {
    T r;
    int i;
    f32 u = 1.0f - t;
    for (i = 0; i < 3; i++) {
        r.a[i] = p->a[i] * u + q->a[i] * t;
        r.b[i] = p->b[i] * u + q->b[i] * t;
    }
    f32 u2 = 1.0f - t;
    r.d = p->d * u2 + q->d * t;
    for (int j = 0; j < 2; j++) {
        r.e[j] = p->e[j] * u2 + q->e[j] * t;
    }
    return r;
}
