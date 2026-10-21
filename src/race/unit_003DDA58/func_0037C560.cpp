/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct Key {
    int pad0;
    f32 t4;
    f32 t8;
    char padC[0x70];
};

struct Self {
    char pad0[0x14];
    f32 m14;
    char pad18[8];
    int count;
    Key *keys;
};

extern "C" f32 func_0037C488(Self *, f32) throw();
extern "C" f32 func_0037C3E8(Self *) throw();
extern "C" int func_0037C4F8(Self *, f32) throw();

extern "C" int func_0037C560(Self *self, Key **out, int max, int mult, f32 base) {
    f32 t = func_0037C488(self, base + (f32)mult * self->m14);
    f32 period = func_0037C3E8(self);
    int idx = func_0037C4F8(self, t);
    int n = 0;
    if (idx >= 0) {
        while (self->keys[idx].t4 <= t && n < max) {
            Key *k = (Key *)(idx * 0x7C + (int)self->keys);
            if (t < k->t8) {
                out[n++] = k;
            }
            idx++;
            if (idx >= self->count) {
                f32 prev = t;
                t -= period;
                idx -= self->count;
                if (!(t < prev))
                    return n;
            }
        }
    }
    return n;
}
