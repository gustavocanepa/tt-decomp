/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct Sub { char pad0[0x18]; s32 f18; char pad1c[0x40]; s32 f5C; s32 f60; };
struct Sub2 { char pad0[0x18]; s32 f18; };
struct Obj { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; Sub *f14; Sub2 *f18; s32 f1C; };
struct Args { s32 a, b; void *c; s32 d, e, f; };
struct Evt { s32 type; char pad4[0xC]; void *p; s16 s0; s16 s1; char pad1[4]; s32 f1; s32 f2; char pad2[4]; };

extern "C" void func_004C4B68(void *, s32, s32, s32, s32);
extern "C" void func_004C4C28(void *, void *);
extern "C" Sub2 *func_004C4FE8(void *);
extern "C" s32 func_004C5128(void *);
extern "C" void func_004C5768(void *, void *);
extern "C" void func_004C5C58(void *, s32, s32, s32);
extern "C" Sub *func_004C6EE0(void);

extern "C" void SePlayer__Play(Obj *o, void *arg1, s32 arg2, s32 arg3, float x, float y, float z) {
    if (o->f0 == 0) return;
    s32 a = (s32)(x * 16383.0f);
    s32 b = (s32)(y * 16383.0f);
    s32 c = (s32)(z * 4096.0f);
    if (o->f4 == 0) {
        Sub2 *s = o->f18;
        if (s != 0) {
            s32 k = s->f18;
            if (o->f1C != k) {
                o->f18 = 0;
                s = 0;
            }
        }
        if (s == 0) {
            Sub2 *t = func_004C4FE8(arg1);
            o->f18 = t;
            if (t == 0) return;
            func_004C4B68(t, o->f0, o->f8, o->fC, o->f10);
            s = o->f18;
            o->f1C = s->f18;
        }
        Args args;
        args.a = a; args.b = b; args.c = arg1; args.d = c; args.e = arg3; args.f = arg2;
        func_004C4C28(s, &args);
    } else {
        Sub *s = o->f14;
        if (s != 0) {
            s32 k = s->f5C;
            if (o->f1C != k) {
                o->f14 = 0;
                s = 0;
            }
        }
        if (s == 0) {
            Sub *t = func_004C6EE0();
            o->f14 = t;
            if (t == 0) return;
            o->f1C = t->f5C;
        }
        Evt e;
        func_004C5128(&e);
        e.type = 0x1E;
        e.s0 = a;
        e.s1 = b;
        e.f1 = arg3;
        e.p = arg1;
        e.f2 = c;
        func_004C5768(o->f14, &e);
        if (o->f14->f60 == 1)
            func_004C5C58(o->f14, o->f0, o->f8, o->fC);
    }
}
