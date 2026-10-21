#include "types.h"

struct VObj { char pad0[4]; char *vtbl; };
struct VEntryCall { short delta; short index; void (*fn)(void *, s32 *, s32, void *); };
struct Obj { char pad0[0xF0]; VObj *handler; s32 f_d8; };

extern "C" s32 func_001D9CC0(Obj *arg0);
extern "C" void func_002A7A30(void *h);
extern "C" void func_002A7578(void *h, s32 *val);
extern "C" void func_002A75A8(void *h, int flags);
extern "C" void func_0029EA18(void *h, s32 val);
extern "C" void func_0029CEF0(void *h, int flags);
extern "C" void func_002C0FE8(s32 p);
extern "C" void func_002C1050(s32 p);

struct Value {
    s32 p;
    Value() { func_002A7A30(this); }
};

static inline void vcall_8C30(VObj *o, s32 *ret, s32 n, void *args) {
    VEntryCall *e = (VEntryCall *)(o->vtbl + 0xC0);
    e->fn((char *)o + e->delta, ret, n, args);
}

/* func_0026B7B0: if func_001D9CC0(self) is nonzero and the handler at self+0xD4 is set,
   builds two Values (the first from arg1, the second from the s32 at self+0xF4), invokes
   the handler (vtable slot 0xA8) with a result slot, then destroys the arguments and the
   result. Returns void. */
extern "C" void func_0026B7B0(void *arg0, s32 arg1) {
    s32 newVal;
    s32 oldVal;
    s32 argv = arg1;
    Obj *self = (Obj *)arg0;
    if (func_001D9CC0(self) != 0) {
        VObj **ph = &self->handler;
        if (*ph != 0) {
            s32 ret[4];

            func_002A7A30(ret);
            {
                Value args[2];
                s32 tmp[4];
                s32 v1;
                s32 *p0;
                Value *dst;

                p0 = tmp;
                dst = args;
                v1 = argv;
                func_002A7578(p0, &v1);
                if (dst != (Value *)p0) {
                    newVal = *p0;
                    if (newVal != 0) {
                        func_002C0FE8(newVal);
                    }
                    oldVal = dst->p;
                    if (oldVal != 0) {
                        func_002C1050(oldVal);
                    }
                    dst->p = newVal;
                }
                func_002A75A8(p0, 2);

                dst = &args[1];
                func_0029EA18(p0, self->f_d8);
                if (dst != (Value *)p0) {
                    newVal = *p0;
                    if (newVal != 0) {
                        func_002C0FE8(newVal);
                    }
                    oldVal = dst->p;
                    if (oldVal != 0) {
                        func_002C1050(oldVal);
                    }
                    dst->p = newVal;
                }
                func_0029CEF0(p0, 2);

                vcall_8C30(*ph, ret, 2, args);
                {
                    Value *q = args + 2;
                    while (args != q) {
                        --q;
                        func_002A75A8(q, 2);
                    }
                }
                func_002A75A8(ret, 2);
            }
        }
    }
}
