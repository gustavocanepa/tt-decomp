/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V2 { float x, y; };
struct Obj {
    int a0; int a4; void *a8; char p0[0x14]; int a20; float a24; float a28; int a2c; int a30;
    float a34; float a38; float a3c; float a40; float a44; float a48; float a4c; float a50; float a54; float a58;
    float a5c; float a60; float a64; float a68; char p1[4]; float a70;
};
extern "C" float func_00396670(int, float, float);
extern "C" float func_003CF038(int) throw() __attribute__((const));
extern "C" float func_003CF068(int) throw() __attribute__((const));
extern "C" void func_003CF2A8(Obj *, int, int, int);

static inline int mode(int x)
{
    if (x < 4)
        return 0xB;
    return 0xE;
}

extern "C" void func_003CF148(Obj *o, int arg1, int arg2, int arg3, int t0, int s4, int s2)
{
    o->a2c = arg3;
    o->a8 = (void *)((char *)o + 0x1C);
    o->a0 = arg1;
    o->a30 = 0;
    o->a68 = func_00396670(s4, 0.0f, 1.0f);
    o->a70 = 0.0f;
    V2 *w = (V2 *)((char *)o + 0x44);
    w->x = 0.0f;
    w->y = 0.0f;
    func_003CF2A8(o, s4, arg1, arg2);
    o->a4c = 0.0f;
    o->a50 = 0.0f;
    o->a54 = 0.0f;
    o->a58 = 0.0f;
    if (s2 == 0) {
        V2 *v = (V2 *)((char *)o + 0x3C);
        o->a4 = 0;
        v->x = o->a34;
        v->y = o->a38;
        float f = func_003CF068(arg2);
        o->a5c = f + func_00396670(s4, -0x1.41b2fp-1f, 0x1.41b2fp-1f);
        o->a60 = 0.0f;
    } else {
        if (s2 < 4) o->a4 = 11;
        else o->a4 = 14;
        V2 *v = (V2 *)((char *)o + 0x3C);
        v->x = o->a24;
        v->y = o->a28;
        float f = func_003CF038(o->a20);
        *(int *)&o->a60 = 0;
        o->a5c = f;
    }
    o->a64 = o->a5c;
}
