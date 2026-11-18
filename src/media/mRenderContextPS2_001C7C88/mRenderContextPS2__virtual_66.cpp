/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rect { char pad0[0x10]; int x, y, dx, dy; };
struct Ctx { int m0, m4, m8, mC, m10, m14, m18, m1C; float f20, f24; int m28, m2C, m30, m34, m38; };
extern "C" void func_00104868(Ctx *, int);
extern "C" void func_00104960(Ctx *, Rect *);
extern "C" void func_00104B10(Ctx *);
extern "C" void func_00104BA8(Ctx *);
extern "C" void func_00104C88(Ctx *);
extern "C" void func_00104D10(Rect *);
extern "C" int func_00104F00(Ctx *);
extern "C" void func_001050C0(Rect *, Ctx *, int, int);
extern "C" Rect *func_001C7088(int) throw();
extern "C" int func_001C7860(void *) throw();
extern "C" void func_0046F0F8(int);
extern "C" void func_004702D8(int, float);
extern "C" void func_00470478(int);
extern "C" void func_00470728(int, int, float);
extern "C" void func_00472268(int, int);
extern "C" void pglPushAttrib(int);
extern "C" void func_00473498(void);
extern "C" void func_00474520(float, float, float, float, float, float, float, float);
extern "C" void func_00477E30(float, float, float, float);
extern "C" void func_00478C98(int);
extern "C" void mRenderContextPS2__virtual_66(void *self, int n, float f) {
    Ctx c;
    if (!(f <= 0.0f) && n < 6) {
        pglPushAttrib(0x887);
        Rect *r = func_001C7088(func_001C7860(self));
        func_00104960(&c, r);
        c.m4 = 0;
        func_00104B10(&c);
        func_00104C88(&c);
        func_00104D10(r);
        func_00472268(3, 1);
        func_00472268(2, 1);
        func_00478C98(4);
        func_00478C98(5);
        func_0046F0F8(6);
        func_00470478(0);
        func_00477E30(1.0f, 1.0f, 1.0f, 1.0f);
        for (int i = 0; i < n; i++) {
            func_00470728(n, i, f);
            func_004702D8(100, 1.0f / (float)(i + 1));
            float w = (float)c.m18;
            func_00474520(0.0f, 0.0f, w, (float)func_00104F00(&c), (float)r->x, (float)r->y, (float)(r->x + r->dx), (float)(r->y + r->dy));
        }
        func_001050C0(r, &c, 1, 1);
        func_00104BA8(&c);
        func_00473498();
        func_00104868(&c, 2);
    }
}
