struct Entry { int w[15]; };
struct Table { Entry e[2]; int m78; };
extern Table D_00579534;
struct Ctx { int m0, m4; };
extern "C" void pglPushAttrib(int);
extern "C" void func_00473050(void);
extern "C" int func_00104960(Ctx *, Entry *);
extern "C" void func_00104B10(Ctx *);
extern "C" void func_001050C0(Ctx *, Entry *, int, int);
extern "C" void func_00104C88(Ctx *);

extern "C" void func_001C9E10(void *self, Ctx *c)
{
    pglPushAttrib(1);
    Entry *e = &D_00579534.e[D_00579534.m78];
    func_00104960(c, e);
    c->m4 = 1;
    func_00104B10(c);
    func_001050C0(c, e, 0, 0);
    func_00104C88(c);
    func_00473050();
}
