/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Sub { char pad0[8]; u16 w; u16 h; };
struct Obj { char pad0[8]; int f8; char padc[0xC]; Sub *f18; Sub *f1C; };
struct Obj2 { char pad0[0x18]; int f18; Sub *f1C; };
extern "C" void func_00104C88(void *);
extern "C" int func_00104E00(void *);
extern "C" int func_00467728(void *);
extern "C" void func_0046AC48(int);
extern "C" void func_004702D8(int, float);
extern "C" void func_00470450(int);
extern "C" void func_00470478(int);
extern "C" void func_004704E0(int);
extern "C" void pglPushAttrib(int);
extern "C" void func_00473498(void);
extern "C" void func_00473DF0(int);
extern "C" void func_00474288(int, int, int, int, int, int, int, int);
extern "C" void func_00477DC0(int);
extern "C" void func_00477E30(float, float, float, float);
extern "C" void func_00478C98(int);

extern "C" int func_0043A640(Obj *a, Obj2 *b, Obj2 *c, float f) {
    Sub *sb = b->f1C; Sub *sc = c->f1C;
    int w = sb->w; int h = sb->h;
    if (sc->w != w || sc->h != h) return 0;
    if (w != a->f8 || h != func_00104E00(a)) return 0;
    pglPushAttrib(0x8C7);
    func_00104C88(a);
    func_004704E0(0);
    func_00473DF0(0);
    func_00478C98(3);
    func_00478C98(4);
    func_00478C98(8);
    func_00470478(0);
    func_004702D8(0x44, 1.0f);
    func_00477DC0(0x80FFFFFF);
    func_00467728(b);
    func_0046AC48(b->f18);
    func_00474288(0, 0, w, h, 0, 0, w, h);
    func_00477E30(1.0f, 1.0f, 1.0f, f);
    func_00470450(0xFFFFFF);
    func_00467728(c);
    func_0046AC48(c->f18);
    func_00474288(0, 0, w, h, 0, 0, w, h);
    func_00470450(-1);
    func_00473498();
    return 1;
}
