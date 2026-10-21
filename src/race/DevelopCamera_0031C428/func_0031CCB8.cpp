typedef int s32;
typedef float f32;

struct Entry { short delta, index; s32 (*fn)(void *, s32); };
struct Out {
    char pad0[4];
    s32 i4;
    f32 f8, fC, f10, f14, f18, f1C;
};
struct Item { char pad[0x18]; s32 i18; };
struct Cam {
    Entry *vt;
};

extern "C" void func_003EBBF8(Out *);
extern "C" s32 func_0031CC60(f32, f32) throw() __attribute__((const));
extern "C" void func_0031D5E0(Cam *, s32, f32 *, s32, f32, f32, f32);

extern "C" Out *func_0031CCB8(Cam *self) {
    f32 v[4];
    s32 idx = *(s32 *)((char *)self + 0xA4C);
    Out *out = *(Out **)((char *)self + 0xCD4);
    Item *item = *(Item **)((char *)self + idx * 0x1B4 + 0x20);
    func_003EBBF8(out);
    if (item != 0) {
        s32 i18 = item->i18;
        Entry *e = (Entry *)((char *)self->vt + 0xE0);
        func_0031D5E0(self, e->fn((char *)self + e->delta, idx), v, i18, 0x1.333332p-3f, 0x1.999998p+0f, 1.4f);
        f32 a = v[0];
        f32 d = v[1];
        f32 b = v[2];
        f32 c = v[3];
        bool r0 = false;
        if (func_0031CC60(a, d) == 0) r0 = true;
        if (func_0031CC60(b, c) == 0) r0 = true;
        if (r0 == 0) {
            if (a <= -1.0f) a = -1.0f;
            if (a >= 1.0f) a = 1.0f;
            if (d <= -1.0f) d = -1.0f;
            if (d >= 1.0f) d = 1.0f;
            if (b <= -1.0f) b = -1.0f;
            if (b >= 1.0f) b = 1.0f;
            if (c <= -1.0f) c = -1.0f;
            if (c >= 1.0f) c = 1.0f;
            out->i4 = 3;
            out->f10 = a;
            out->f14 = b;
            out->f18 = d;
            out->f1C = c;
            out->f8 = (a + d) * 0.5f;
            out->fC = (b + c) * 0.5f;
        }
    }
    return out;
}
