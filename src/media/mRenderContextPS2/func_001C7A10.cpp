typedef short s16;
typedef float f32;

struct VE_00215D30 {
    s16 delta;
    s16 index;
    void (*fn)(void *, f32, f32, f32, f32);
};

struct Self_00215D30 {
    char pad0[4];
    char *inner;
};

static inline void call_00215D30(char *self, f32 a, f32 b, f32 c, f32 d) {
    char *in = ((Self_00215D30 *)self)->inner;
    VE_00215D30 *e = (VE_00215D30 *)(in + 0x1C0);
    e->fn(self + e->delta, a, b, c, d);
}

extern "C" void func_001C7A10(char *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    f32 k2 = 2.0f;
    f32 k4 = 4.0f;
    f32 x0 = fparg0 - k2;
    f32 x1 = fparg1 - k2;
    f32 z3 = fparg3 + k4;
    f32 z2 = fparg2 + k4;
    call_00215D30(arg0, x0, x1, k2, z3);
    call_00215D30(arg0, x0, x1, z2, k2);
    call_00215D30(arg0, x0, fparg1 + fparg3, z2, k2);
    call_00215D30(arg0, fparg0 + fparg2, x1, k2, z3);
}
