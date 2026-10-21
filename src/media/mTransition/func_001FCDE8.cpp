/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Handle {
    s32 p;
    char pad[0xC];
};

struct VEntry58 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VEntry1E0 {
    s16 delta;
    s16 index;
    float (*fn)(void *, s32, s32);
};

struct VObj {
    char pad[4];
    char *vtbl;
};

static inline s32 vcall_58(VObj *o) {
    VEntry58 *e = (VEntry58 *)(o->vtbl + 0x68);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_001FCB00(void *arg0, int arg1) throw();
extern "C" void func_001FCB58(void *arg0, void *arg1) throw();
extern "C" void func_00299AB0(void *arg0, int arg1);
extern "C" void func_0029B380(void *arg0, float fparg0);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_001FCDE8(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    Handle a;
    VObj **args = arg3;
    s32 *dst = arg0;
    if (arg2 == 2) {
        Handle h;
        Handle *ph;
        func_001FCB58(&a, arg1);
        {
            VObj *self = (VObj *)a.p;
            VEntry1E0 *e = (VEntry1E0 *)(self->vtbl + 0x210);
            void *adj = (char *)self + e->delta;
            s32 x = vcall_58(args[0]);
            s32 y = vcall_58(args[1]);
            float f = e->fn(adj, x, y);
            ph = &h;
            func_0029B380(ph, f);
        }
        if ((void *)dst != (void *)ph) {
            s32 newVal = ph->p;
            s32 oldVal;
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *dst;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *dst = newVal;
        }
        func_00299AB0(ph, 2);
        func_001FCB00(&a, 2);
    }
}
