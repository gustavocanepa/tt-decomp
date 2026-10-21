typedef int s32;
typedef short s16;

struct RefCounter;

extern "C" void func_002A7A30(void *a0);
extern "C" void func_002A75A8(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);

struct VObj { char pad0[4]; char *vtbl; };
struct ObjH { char pad0[4]; VObj *handler; };
struct VEntryCall { s16 delta; s16 index; void (*fn)(void *, s32 *, s32, void *); };
struct VEntryB { s16 delta; s16 index; s32 (*fn)(void *); };

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

/* func_0052A348: func_0052A348. Builds one Value from arg1, a result slot,
   calls the handler (vtable slot 0xA8), tests the returned object's slot 0x58,
   releases the result and the argument list, and returns whether that test was nonzero. */
extern "C" s32 func_0052A348(ObjH *self, Value *arg1) {
    s32 newVal;
    s32 oldVal;
    s32 r;
    {
        Value args[1];
        s32 ret[4];
        s32 *pr;

        if (args != arg1) {
            newVal = arg1->p;
            if (newVal != 0) {
                func_002C0FE8((RefCounter *)newVal);
            }
            oldVal = args[0].p;
            if (oldVal != 0) {
                func_002C1050((RefCounter *)oldVal);
            }
            args[0].p = newVal;
        }

        pr = ret;
        func_002A7A30(pr);
        vcall20(self->handler, pr, 1, args);
        r = vcall58((char *)pr[0]) != 0;
        func_002A75A8(pr, 2);

        {
            Value *q = args + 1;
            while (args != q) {
                --q;
                func_002A75A8(q, 2);
            }
        }
    }
    return r;
}
