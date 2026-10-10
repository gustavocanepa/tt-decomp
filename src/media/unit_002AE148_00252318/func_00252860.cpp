typedef int s32;

struct Handle {
    void *p;
    char pad[0xC];
};

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct VObj {
    char pad0[4];
    VEntry *vtbl;
};

extern "C" void func_00251620(void *arg0, int arg1);
extern "C" void func_00251678(void *arg0, void *arg1);
extern "C" s32 func_00257D20(void *a, s32 b);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, bool arg1);
extern "C" void func_002C0FE8(void *p);
extern "C" void func_002C1050(void *p);

static inline s32 vcall(VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x68);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_00252860(void **arg0, void *arg1, s32 arg2, VObj **arg3) {
    if (arg2 == 1) {
        Handle o;
        Handle h;
        Handle *ph;
        void *op;
        bool b;
        func_00251678(&o, arg1);
        op = o.p;
        b = func_00257D20(op, vcall(*arg3)) != 0;
        ph = &h;
        func_0029EA18(ph, b);
        if ((void *)arg0 != (void *)ph) {
            void *p = ph->p;
            if (p != 0) {
                func_002C0FE8(p);
            }
            if (*arg0 != 0) {
                func_002C1050(*arg0);
            }
            *arg0 = p;
        }
        func_0029CEF0(ph, 2);
        func_00251620(&o, 2);
    }
}
