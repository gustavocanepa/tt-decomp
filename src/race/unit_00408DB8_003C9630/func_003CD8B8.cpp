/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;

struct Row { float a, b, c, d; };

static inline float dot3(const float *v, const Row &r) {
    return v[0] * r.a + v[1] * r.b + v[2] * r.c;
}

extern "C" void func_003CD8B8(const Row *m, const float *v, float *out) {
    int i=0;
    bool more;
    do {
        float value = dot3(v, m[i]);
        i++;
        more = i < 3;
        *out++ = value;
    } while(more);
}
