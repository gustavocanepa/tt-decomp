/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

static inline void rect(f32 *r, f32 x, f32 y, f32 w, f32 h) { r[0]=x; r[1]=y; r[2]=w; r[3]=h; }

struct Movie {
    char pad0[0x10];
    f32 w;
    f32 h;
};

struct Self {
    char pad0[0xC];
    Movie *movie;
    void *unk10;
    char pad14[8];
    s32 unk1C;
};

extern "C" void func_001DED70(void *, void *);
extern "C" char *func_001E49C8(void *);
extern "C" f32 func_001E4CA8(void *);
extern "C" void func_001E50F0(void *);
extern "C" void func_001E5128(void *);
extern "C" void func_00439930(void *);
extern "C" void func_0043A0E8(s32 *);
extern "C" void func_0043A110(s32 *);
extern "C" void func_0043AE50(void *, void *, f32, s32);
extern "C" void func_0043AF18(void *, void *);
extern "C" void func_0043C8F0(void *, void *, s32);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004755EC(f32, f32, f32);
extern "C" void func_00475638(f32, f32, f32);

extern "C" void mFlashPS2__virtual_13(Self *self, void *arg1, f32 fw, f32 fh, f32 alpha) {
    f32 v[4];
    s32 m[12];
    f32 r[4];
    f32 zero;
    if (self->unk1C != 0) {
        if (self->unk10 == 0) return;
        if (self->movie == 0) return;
    } else {
        if (self->movie == 0) return;
    }
    zero = 0.0f;
    v[2] = fw;
    v[3] = fh;
    v[0] = zero;
    v[1] = zero;
    func_001DED70(v, func_001E49C8(arg1));
    func_00439930(m);
    func_00473050();
    func_0043A0E8(m);
    {
        Movie *mv = self->movie;
        f32 mw = mv->w;
        f32 mh = mv->h;
        f32 s = minf(v[2] / mw, v[3] / mh);
        f32 w = mw * s;
        f32 h = mh * s;
        rect(r, v[0] + (v[2] - w) * 0.5f,
             v[1] + (v[3] - h) * 0.5f, w + 0.5f, h + 0.5f);
        func_004755EC(r[0], r[1], zero);
        func_00475638(s, s, 1.0f);
    }
    func_001E50F0(arg1);
    func_0043AF18(self->movie, m);
    {
        s32 col = ((s32)(func_001E4CA8(arg1) * 128.0f) << 24) | 0xFFFFFF;
        if (self->unk1C != 0) {
            func_0043C8F0(self->unk10, m, col);
        } else {
            func_0043AE50(self->movie, m, alpha, col);
        }
    }
    func_001E5128(arg1);
    func_0043A110(m);
    func_004730A8();
}
