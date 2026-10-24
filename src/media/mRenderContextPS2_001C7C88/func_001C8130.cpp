/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rect { char pad0[0x10]; int x, y, dx, dy; };
struct Ctx { char pad[8]; int width; };
extern "C" void func_00104C88(Ctx *);
extern "C" void func_00104D10(Rect *);
extern "C" int func_00104E00(Ctx *);
extern "C" void func_0046F0F8(int);
extern "C" void func_00470450(int);
extern "C" void func_00470478(int);
extern "C" void func_00472268(int, int);
extern "C" void pglPushAttrib(int);
extern "C" void func_00473498(void);
extern "C" void func_00474520(float, float, float, float, float, float, float, float);
extern "C" void func_00477E30(float, float, float, float);
extern "C" void func_00478C98(int);
extern "C" void func_001C8130(Rect *r, Ctx *c, int mode, float dx, float dy) {
    func_00470450(0xFFFFFF);
    pglPushAttrib(0x887);
    func_00104D10(r);
    func_00104C88(c);
    func_00472268(3, mode);
    func_00472268(2, mode);
    func_00478C98(4);
    func_00478C98(5);
    func_0046F0F8(6);
    func_00470478(0);
    func_00477E30(1.0f, 1.0f, 1.0f, 1.0f);
    float w = (float)c->width;
    float h = (float)func_00104E00(c);
    float x0 = (float)r->x + dx;
    float x1 = (float)(r->x + r->dx) + dx;
    float y1 = (float)(r->y + r->dy) + dy;
    float y0 = (float)r->y + dy;
    func_00474520(0.0f, 0.0f, w, h, x0, y0, x1, y1);
    func_00473498();
    func_00470450(-1);
}
