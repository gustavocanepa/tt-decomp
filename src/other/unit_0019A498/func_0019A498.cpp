typedef int s32;

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct Obj {
    struct VEntry *vtbl;
};

extern s32 func_0019A200(struct Obj *, s32);
extern s32 func_0019A2B8(void);

static inline s32 vcall(struct Obj *obj, int off)
{
    struct VEntry *e = (struct VEntry *)((char *)obj->vtbl + off);
    return e->fn((char *)obj + e->delta);
}

s32 func_0019A498(struct Obj *arg0)
{
    if (vcall(arg0, 0x18) == 0 || vcall(arg0, 0x20) == 0) {
        return 3;
    }

    return func_0019A200(arg0, func_0019A2B8());
}
