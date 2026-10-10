/* mButton virtual 77: if the script handler at this+0xB0 is set, builds a 2-element argument list (arg1 via func_002A7578, arg2 via func_00262520), invokes the handler (vtable slot 0xA8) into a result value, destroys the arguments and the result; returns 1 */
typedef int s32;

struct VObj { char pad0[4]; char *vtbl; };
struct VEntryCall { short delta; short index; void (*fn)(void *, s32 *, s32, void *); };
struct Obj { char pad0[0xD4]; VObj *handler; };

extern "C" void func_002A7A30(void *h);
extern "C" void func_002A7578(void *h, s32 *val);
extern "C" void func_002A75A8(void *h, int flags);
extern "C" void func_00262520(void *h, s32 *val);
extern "C" void func_00262550(void *h, int flags);
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

extern "C" s32 mButton__onMotion(Obj *self, s32 arg1, s32 arg2) {
    s32 newVal;
    s32 oldVal;
    VObj **ph = &self->handler;
    if (*ph != 0) {
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
            func_00262520(p0, &v2);
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
            func_00262550(p0, 2);

            vcall20(*ph, ret, 2, args);
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
    return 1;
}
