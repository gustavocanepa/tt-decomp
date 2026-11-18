/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

struct VE3 { s16 delta; s16 index; void (*fn)(void *, void *, s32, f32); };
struct VE2 { s16 delta; s16 index; void (*fn)(void *, void *); };
struct Rect { f32 x, y, w, h, s; };
static inline void setRect(Rect *r, f32 scale, f32 x, f32 y, f32 w, f32 h) {
    r->y=y; r->x=x; r->w=w; r->h=h; r->s=scale;
}
struct G {
    char pad0[0x64];
    char *vt;
    char pad68[0xE390 - 0x68];
    Rect r;
};

struct Table { char pad[0x78]; s32 cur; };
extern "C" Table D_00579534;
extern "C" G *D_005798BC;

extern "C" void func_00104838(char *);
extern "C" void func_00104868(char *, int);
extern "C" void *func_00104960(char *, void *);
extern "C" void func_00104AA8(char *, s32, s32, s32, s32);
extern "C" f32 func_00205C50(void *);
extern "C" f32 func_00205CB0(void *);
extern "C" f32 func_00205D10(void *);
extern "C" f32 func_00205D70(void *);
extern "C" void func_0046F0F8(s32);
extern "C" void func_00478C98(s32);

extern "C" void func_0011FBD0(void *widget) {
    char buf[0x40];
    s32 x = (s32)func_00205C50(widget);
    s32 y = (s32)func_00205CB0(widget);
    s32 w = (s32)func_00205D10(widget);
    s32 h = (s32)func_00205D70(widget);
    func_00478C98(0x12);
    void *elem = (char *)&D_00579534 + D_00579534.cur * 0x3C;
    func_00104838(buf);
    func_00104960(buf, elem);
    func_00104AA8(buf, x, y, w, h);
    G *g = D_005798BC;
    Rect *r = &g->r;
    setRect(r, 1.3f, (f32)(w / 2 - 60), 10.0f, 120.0f, 32.0f);
    G *a = D_005798BC;
    VE3 *e1 = (VE3 *)(a->vt + 0x388);
    e1->fn((char *)a + e1->delta, buf, 0, 1.0f);
    G *b = D_005798BC;
    VE2 *e2 = (VE2 *)(b->vt + 0x380);
    e2->fn((char *)b + e2->delta, buf);
    func_0046F0F8(0x12);
    func_00104868(buf, 2);
}
