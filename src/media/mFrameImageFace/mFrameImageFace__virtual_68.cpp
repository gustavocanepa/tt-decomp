typedef int s32;

struct Handle {
    s32 p;
};

struct Obj {
    char pad0[0x198];
    Handle h[8];
};

extern "C" void func_00243750(void);
extern "C" void func_001C1380(Handle *, s32 *);
extern "C" void func_001C13B0(Handle *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

static inline void assign(Handle *dst, Handle *src) {
    if (dst != src) {
        s32 v = src->p;
        if (v != 0) {
            func_002C0FE8(v);
        }
        if (dst->p != 0) {
            func_002C1050(dst->p);
        }
        dst->p = v;
    }
}

#define SET(i, z)                       \
    {                                   \
        Handle *d = &self->h[i];        \
        z = 0;                          \
        func_001C1380(&tmp[0], &z);        \
        assign(d, &tmp[0]);                \
        func_001C13B0(&tmp[0], 2);         \
    }

extern "C" void mFrameImageFace__virtual_68(Obj *self) {
    Handle tmp[4];
    s32 z0, z1, z2, z3, z4, z5, z6, z7;

    func_00243750();
    SET(0, z0)
    SET(1, z1)
    SET(2, z2)
    SET(3, z3)
    SET(4, z4)
    SET(5, z5)
    SET(6, z6)
    SET(7, z7)
}
