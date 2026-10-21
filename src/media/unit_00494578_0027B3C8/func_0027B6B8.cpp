#include "types.h"

struct VObj { char pad0[4]; char *vtbl; };
struct VEntryCall { s16 delta; s16 index; void (*fn)(void *, s32 *, s32, void *); };
struct VEntryB { s16 delta; s16 index; s32 (*fn)(void *); };

extern "C" void func_002A7A30(void *h);
extern "C" void func_002A7578(void *h, s32 *val);
extern "C" void func_002A75A8(void *h, s32 flags);
extern "C" void func_002C0FE8(s32 p);
extern "C" void func_002C1050(s32 p);

struct Value {
    s32 p;
    Value() { func_002A7A30(this); }
};

static inline void vcall20(VObj *o, s32 *ret, s32 n, void *args) {
    VEntryCall *e = (VEntryCall *)(o->vtbl + 0xC0);
    e->fn((char *)o + e->delta, ret, n, args);
}

static inline s32 vcall58(char *o) {
    VEntryB *e = (VEntryB *)(((VObj *)o)->vtbl + 0x68);
    return e->fn(o + e->delta);
}

/* func_0027B6B8: builds two Values from arg1 and arg2, a result slot, calls the
   object at *arg0 (vtable slot 0xA8), tests the returned object's slot 0x58 and
   returns its value, releasing the result and the argument list. */
extern "C" s32 func_0027B6B8(VObj **arg0, s32 arg1, s32 arg2) {
    s32 newVal;
    s32 oldVal;
    s32 r;
    s32 ret[4];

    func_002A7A30(ret);
    {
        Value args[2];
        s32 tmp[4];
        s32 v1;
        s32 v2;
        s32 *p0;
        Value *dst;

        p0 = tmp;
        dst = args;
        v1 = arg1;
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
        v2 = arg2;
        func_002A7578(p0, &v2);
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

        vcall20(*arg0, ret, 2, args);
        r = vcall58((char *)ret[0]);
        {
            Value *q = args + 2;
            while (args != q) {
                --q;
                func_002A75A8(q, 2);
            }
        }
        func_002A75A8(ret, 2);
    }
    return r;
}
