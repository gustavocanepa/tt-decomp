/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { char pad[0x28]; float x, y, z; };

static inline float Abs(float a) {
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(a));
    return r;
}

extern "C" void func_002DED58(Self *s) {
    if (Abs(s->x) > 20.0f || Abs(s->y) > 20.0f || Abs(s->z) > 20.0f) {
        s->x *= 0x1.999998p-3f;
        s->y *= 0x1.999998p-3f;
        s->z *= 0x1.999998p-3f;
    }
}
