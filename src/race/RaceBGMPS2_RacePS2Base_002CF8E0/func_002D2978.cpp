/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct VEntry { short delta; short index; void *fn; };
struct Obj { VEntry *vt; };
struct Base { char pad0[0x64]; char *vt; char pad1[0xD034 - 0x68]; f32 vol; };
extern f32 D_00583FC8;
extern "C" void func_002CFED8(void *, f32) throw();
static inline f32 getv(Base *self) {
    VEntry *e = (VEntry *)(self->vt + 0x4B8);
    return ((f32 (*)(void *))e->fn)((char *)self + e->delta);
}
static inline Obj *getobj(Base *self) {
    VEntry *e = (VEntry *)(self->vt + 0xD0);
    return ((Obj *(*)(void *, s32))e->fn)((char *)self + e->delta, 0);
}
extern "C" void func_002D2978(Base *self) {
    f32 v = getv(self);
    self->vol = self->vol * 0.5f;
    Obj *o = getobj(self);
    VEntry *e2 = (VEntry *)((char *)o->vt + 0x140);
    if (((s32 (*)(void *, s32))e2->fn)((char *)o + e2->delta, 0) != 0)
        self->vol = 1.0f;
    D_00583FC8 = v * (1.0f - self->vol);
    func_002CFED8((char *)self + 0xD038, v);
}
