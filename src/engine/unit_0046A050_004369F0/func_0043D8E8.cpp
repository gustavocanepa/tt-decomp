/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Val { s32 type; s32 v; };
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043D3B8(Val *, const Val *);
extern "C" void func_0043D438(Val *);
extern "C" void *exception__structor_0(s32 size);

struct Obj {
    s32 ref;
    s32 f4;
    s16 f8;
    s16 fA;
    s32 fC;
    s32 f10;
    Val val;
    s32 f1C;
};

extern "C" void func_0043D8E8(Val *self, const Obj *src) {
    s32 type = 13;
    Obj *o;
    func_0043D510(self);
    self->type = type;
    o = (Obj *)exception__structor_0(0x20);
    o->ref = 0;
    o->f4 = src->f4;
    o->f8 = src->f8;
    o->fA = src->fA;
    o->fC = src->fC;
    o->f10 = src->f10;
    func_0043D3B8(&o->val, &src->val);
    o->f1C = src->f1C;
    func_0043D438(&o->val);
    self->v = (s32)o;
}
