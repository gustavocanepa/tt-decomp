/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

struct Obj {
    char pad0[0x80];
    s32 unk80;
};

struct Out {
    s32 id;
    s32 mB0;
    s32 hit;
    f32 pos;
};

struct Ctx {
    Obj *p0;
    char *p4;
    char *p8;
    char pad0C[4];
    s32 p10;
    void *p14;
    s32 *p18;
    void *p1C;
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 f);
};

extern "C" void func_003A8E08(Obj *o, void *s, Out *out);
extern "C" s32 func_003A8DC8(s32 hit, f32 pos);
extern "C" f32 func_005357F8(void *a);

extern "C" bool func_0031F8B0(Ctx *arg0)
{
    Out out;
    s32 s3;
    s32 hit;
    s32 r;
    char *t2;

    s3 = arg0->p0->unk80;
    func_003A8E08(arg0->p0, arg0->p14, &out);
    if (out.hit == 0) {
        return 0;
    }
    hit = out.hit;
    r = func_003A8DC8(hit, out.pos);
    f32 f = func_005357F8(arg0->p1C);
    t2 = arg0->p8;
    VEntry *e = (VEntry *)(*(char **)t2 + 0x148);
    e->fn(t2 + e->delta, arg0->p14, s3, out.mB0, hit, r, f);
    char *slot=arg0->p4;
    slot+=arg0->p10*0x1B4;
    *(char **)(slot+0x154)=arg0->p8;
    *arg0->p18 = 1;
    return 1;
}
