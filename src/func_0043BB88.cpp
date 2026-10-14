/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;

struct Rep2 {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    inline char *grab();
};
extern "C" char *strobe__toUpper(Rep2 *r);
extern Rep2 D_005A4C58;
inline char *Rep2::grab() {
    if (selfish)
        return strobe__toUpper(this);
    ++ref;
    return data();
}

struct Str {
    char *dat;
    Str() : dat(D_005A4C58.grab()) {}
};
struct P2 {
    int a;
    int b;
    P2() { a = 0; b = 0; }
};
struct P3 {
    int a;
    int b;
    int c;
    P3() { a = 0; b = 0; c = 0; }
};
extern "C" void *func_00443C60(void *);
inline void *operator new(unsigned int, void *p) { return p; }

struct Obj {
    int f0;
    Obj *f4;
    Obj *f8;
    int fC;
    int f10;
    int f14;
    int f18;
    char p1[4];
    int f20;
    int f24;
    int f28;
    char p2[4];
    P2 m30;
    P2 m38;
    char m40[0x124];
    int f164;
    Str s168;
    int f16C;
    char p4[4];
    int f174;
    char p5[4];
    Str s17C;
    P3 m180;
    int f18C;
    char p6[4];
    P2 m194;
};

extern "C" void func_0043BE20(Obj *, int);

extern "C" void func_0043BB88(Obj *self, int a, int b, int c)
{
    char pad[16];
    self->f0 = 0;
    self->f4 = self;
    self->f8 = self;
    self->fC = a;
    self->f10 = 0;
    self->f14 = 1;
    self->f18 = 1;
    self->f24 = 0;
    self->f28 = 0;
    new (&self->m30) P2;
    new (&self->m38) P2;
    func_00443C60(self->m40);
    self->f164 = c;
    new (&self->s168) Str;
    self->f174 = 1;
    self->f16C = 0;
    new (&self->s17C) Str;
    new (&self->m180) P3;
    self->f18C = 1;
    new (&self->m194) P2;
    func_0043BE20(self, b);
}
