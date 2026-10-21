/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct VObj {
    char pad0[4];
    char *vtbl;
};

struct VEntryCall {
    short delta;
    short index;
    void (*fn)(void *, s32 *, s32, void *);
};

struct Obj {
    char pad0[0xE0];
    s32 bc;
    char padC0[0x34];
    VObj *hF4;
};

struct Str1 {
    char pad[0xE8];
    char *p;
};

extern char D_005F0160[];

extern "C" Str1 *func_001E4EA0(char *arg0);
extern "C" void func_001EDBE0(void *arg0, int arg1);
extern "C" void func_001EEB30(s32 a0, const char *a1);
extern "C" void func_001EEDE8(void *arg0);
extern "C" void func_0029CEF0(void *h, int flags);
extern "C" void func_0029EA18(void *h, s32 v);
extern "C" void func_002A7578(void *h, s32 *val);
extern "C" void func_002A75A8(void *h, int flags);
extern "C" void func_002A7A30(void *h);
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

extern "C" void func_0027DA28(Obj *self, char *arg1) {
    s32 newVal;
    s32 oldVal;
    VObj **ph = &self->hF4;
    if (*ph != 0) {
        Str1 *o = func_001E4EA0(arg1);
        if (o != 0) {
            s32 x[4];
            char **pp = &o->p;
            func_001EEDE8(x);
            const char *str;
            s32 xv = x[0];
            s32 len = *(s32 *)(*pp - 0x10);
            if (len == 0) {
                str = D_005F0160;
            } else {
                (*pp)[len] = 0;
                str = *pp;
            }
            func_001EEB30(xv, str);
            func_001EDBE0(x, 2);
        }
        {
            s32 ret[4];
            func_002A7A30(ret);
            Value args[2];
            s32 tmp[4];
            s32 v1;
            s32 *p0;
            Value *dst;

            p0 = tmp;
            dst = args;
            v1 = (s32)arg1;
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
            func_0029EA18(p0, self->bc);
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
}
