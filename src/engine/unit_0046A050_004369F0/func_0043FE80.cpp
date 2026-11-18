/* compiler: ee-gcc2.96-no-strict-aliasing */
inline void *operator new(unsigned, void *p) { return p; }
struct Inner { Inner() {} };
struct Blank { Inner i; char pad[0x1F]; };
struct Holder { Blank a[1024]; };

struct Obj {
    char pad0[0x5000];
    int i5000;
    int pad5004;
    char sub[0x6E14 - 0x5008];
    int i6E14;
    char s6E18[4];
    int i6E1C_;
    int i6E20;
    float f6E24;
    float f6E28;
    int pad6E2C;
    int i6E30, i6E34, i6E38;
    char s6E3C[0x6E7C - 0x6E3C];
    int i6E7C;
    int i6E80, i6E84;
};
struct Sub2 { char pad[0x1E04]; void *a; int b; };
extern "C" void func_005690D8(void *);
extern "C" void *func_005690B0(void *);
struct Color { unsigned v; Color(unsigned x):v(x) {} ~Color() {} };
extern "C" void func_00445498(void *, unsigned);
extern "C" void func_004752F8(void *);

extern "C" int func_0043FE80(Obj *o, int a1, int a2, int a3, int t0, float f) {
    new (o) Holder;
    o->i5000 = 0;
    char *s = (char *)o + 0x5008;
    func_005690D8(s);
    void *r = func_005690B0(s);
    ((Sub2 *)s)->b = 0;
    ((Sub2 *)s)->a = r;
    o->i6E14 = a1;
    o->i6E20 = a2;
    o->f6E24 = f;
    o->f6E28 = 1.0f;
    o->i6E7C = t0;
    o->i6E30 = 0;
    o->i6E34 = 0;
    o->i6E38 = 0;
    int *pair = &o->i6E80;
    pair[0] = 0;
    pair[1] = 0;
    unsigned tmp[4];
    tmp[0] = a3;
    func_00445498(o->s6E18, tmp[0]);
    func_004752F8(o->s6E3C);
}
