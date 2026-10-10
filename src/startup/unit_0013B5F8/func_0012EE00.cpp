typedef int s32;

struct Handle {
    void *p;
    char pad[0xC];
};

struct VEntry {
    short delta;
    short index;
    void *(*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern "C" void func_00128418(void *arg0, int arg1);
extern "C" void func_00128470(void *arg0, void *arg1);
extern "C" s32 func_004122D8(void *arg0);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, int arg1);
extern "C" void func_002C0FE8(void *p);
extern "C" void func_002C1050(void *p);

static inline void *vcall(Obj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x68);
    return e->fn((char *)o + e->delta);
}

static inline void assign(void **dst, Handle *ph) {
    if ((void *)dst != (void *)ph) {
        void *p = ph->p;
        if (p != 0) {
            func_002C0FE8(p);
        }
        if (*dst != 0) {
            func_002C1050(*dst);
        }
        *dst = p;
    }
}

extern "C" void func_0012EE00(void **arg0, void *arg1, s32 n, Obj **args) {
    if (n > 0) {
        Handle h0;
        Handle h;
        func_00128470(&h0, arg1);
        {
            s32 v = func_004122D8(vcall(*args));
            Handle *ph = &h;
            func_0029EA18(ph, v != 0);
            assign(arg0, ph);
            func_0029CEF0(ph, 2);
        }
        func_00128418(&h0, 2);
    }
}
