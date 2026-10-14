/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
struct Item { s32 w[9]; };
struct Info;
typedef int Cnt;
struct Vec { Item *begin; Cnt size; Item &operator[](int i) { Item *p=begin+i; return *p; } };
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct SV { const char *p; s32 len; };
struct Info { char pad0[2]; short f2; char pad4[4]; u16 f8; char padA[0xe]; Vec v18; SV f20; };
struct Info;
struct Str { char *p; };
struct Self {
    s32 f0; Info *f4; Item i8; char pad2c_[0]; Item i2c; s32 f50; Str s; s32 f58; s32 f5C;
};
extern "C" void func_0043BAE8(void *) throw();
extern "C" s32 func_004A8368(const char *) throw();
extern "C" char *strobe__toUpper(void *);
extern "C" void *func_00550E18(void *, u32, u32, const char *, u32);
extern char D_005A4C58[];
extern char D_005D9E78[];

static inline const int &mn(const int &a, const int &b) { return b < a ? b : a; }

extern "C" void func_00443F98(Self *self, s32 a1, Info *a2, s32 a3, Cnt a4, s32 a5) {
    Str *ps = &self->s;
    self->f0 = a1;
    self->f5C = (s32)D_005D9E78;
    self->f4 = a2;
    Rep *g = (Rep *)D_005A4C58;
    char *r;
    if (g->sel != 0) {
        r = (char *)strobe__toUpper(g);
    } else {
        r = (char *)((char *)g + 0x10);
        g->ref++;
    }
    ps->p = r;
    self->f58 = a5;
    Info *info = self->f4;
    if (!info) {
        self->f50 = 0;
        func_0043BAE8(&self->i8);
        func_0043BAE8(&self->i2c);
    } else {
        SV *sv = &info->f20;
        if (sv->len != 0) {
            const char *q = sv->p;
            func_00550E18(ps, 0, (u32)-1, q, func_004A8368(q));
            info = self->f4;
        }
        self->f50 = info->f8;
        a4 = (Cnt)((s32)a4 - info->f2);
        Cnt sp4;
        Vec *v = &info->v18;
        if (v->size != 0) {
            self->i2c = (*v)[mn(a4, v->size - 1)];
        } else {
            func_0043BAE8(&self->i2c);
        }
    }
}
