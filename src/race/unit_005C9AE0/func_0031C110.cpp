typedef short s16;
typedef int s32;
typedef float f32;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Obj {
    VEntry *vtbl;
};

struct Owner {
    VEntry *vtbl;
    char pad4[0xA4C - 4];
    s32 unk9BC;
};

typedef Obj *(*ObjFn)(void *self, s32 arg);
typedef f32 (*FFn)(void *self, f32 arg);

f32 func_0031C110(Owner *arg0, f32 fparg0) {
    f32 var_f0;
    VEntry *e = (VEntry *)((char *)arg0->vtbl + 0xE0);
    Obj *obj = ((ObjFn)e->fn)((char *)arg0 + e->delta, arg0->unk9BC);
    var_f0 = 0.0f;
    if (obj != 0) {
        VEntry *f = (VEntry *)((char *)obj->vtbl + 0x20);
        var_f0 = ((FFn)f->fn)((char *)obj + f->delta, fparg0);
    }
    return var_f0;
}
