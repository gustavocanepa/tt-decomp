/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S {
    char pad0[0x6E4];
    float f6C8;
    float f6CC;
    float f6D0;
};

static inline void update(S *s, const float &v) {
    float old = s->f6CC;
    float next = v;
    s->f6D0 = next;
    if (old < next) s->f6CC = next;
}
extern "C" void func_0030AA68(S *s, float v) {
    s->f6C8 = v;
    update(s, s->f6C8);
}
