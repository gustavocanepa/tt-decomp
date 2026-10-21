/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Val;
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043D3B8(Val *, const Val *);

struct Val {
    s32 type;
    s32 v;
    Val() : type(1) {}
    Val(const Val &o) { func_0043D3B8(this, &o); }
    ~Val() { func_0043D510(this); }
    bool isObj() const { return type == 13; }
};
/* the same two words passed by value: the callee owns the copy, no destructor runs here */
struct ValRaw {
    s32 a;
    s32 b;
};

struct Holder { char pad[8]; char *item; };
struct Obj { char pad[0x164]; Holder *h; };

extern "C" Val func_00441118(s32 p, s32 a2, s32 n, s32 t0, Obj *o);
extern "C" void func_0043CA48(Obj *, s32, const char *) throw();
extern "C" s32 func_0043CAB0(Obj *, const char *, const char *);
extern "C" void func_0043CB08(Obj *, ValRaw *, const char *) throw();
extern "C" void func_0043CB88(Obj *) throw();
extern "C" void func_0043CF10(Obj *, int) throw();
extern "C" void func_0043CFA0(Obj *, ValRaw *) throw();
extern "C" void func_0043D780(Val *, s32) throw();
extern "C" const char *strobe__Any__toString(Val *) throw();
extern "C" float func_0043E0B0(Val *) throw();
extern "C" void func_0043F408(Val *, int) throw();
extern "C" void func_0043F510(Val *);
extern "C" s32 func_0043F5B8(Val *);
extern "C" s32 func_0043F608(Val *);
extern "C" void func_00447CD8(Holder *);
extern "C" void func_00447D00(Holder *, s32);
extern char D_00601488[];

static inline int indexOf(Val *v) {
    func_0043F408(v, 10);
    return (int)func_0043E0B0(v) - 1;
}

#define ITEM(h) ((Val *)((h)->item - 8))

extern "C" Val func_0043E4E0(Val *v, s32 a2, s32 n, s32 t0, Obj *o)
{
    Holder *h = o->h;
    switch (v->type) {
    case 13:
        return func_00441118(v->v, a2, n, t0, o);
    case 17:
        if (n != 0) {
            Val t(*ITEM(h));
            func_0043F510(&t);
            func_00447D00(h, n);
            return t;
        }
        break;
    case 18:
        if (n != 0) {
            Val t(*ITEM(h));
            strobe__Any__toString(&t);
            func_00447D00(h, n);
            return t;
        }
        break;
    case 19:
    case 20:
        if (n != 0) {
            Val t(*ITEM(h));
            func_0043F408(&t, 10);
            func_00447D00(h, n);
            return t;
        }
        break;
    case 21:
        if (n != 0) {
            Val t(*ITEM(h));
            n--;
            func_00447CD8(h);
            int base = n == 0 ? 10 : (int)func_0043E0B0(ITEM(h));
            func_00447D00(h, n);
            func_0043F408(&t, base);
            return t;
        }
        break;
    case 22:
        if (n != 0) {
            Val t;
            func_0043D780(&t, func_0043F5B8(ITEM(h)));
            func_00447D00(h, n);
            return t;
        }
        break;
    case 23:
        if (n != 0) {
            Val t;
            func_0043D780(&t, func_0043F608(ITEM(h)));
            func_00447D00(h, n);
            return t;
        }
        break;
    case 24:
        if (n != 0) {
            Val t(*ITEM(h));
            n--;
            func_00447CD8(h);
            const char *name = D_00601488;
            if (n != 0)
                name = strobe__Any__toString(ITEM(h));
            if (t.isObj()) {
                ValRaw c;
                func_0043D3B8((Val *)&c, &t);
                func_0043CB08(o, &c, name);
            } else if (func_0043F5B8(&t) != 0) {
                func_0043CAB0(o, strobe__Any__toString(&t), name);
            } else {
                int i = indexOf(&t);
                if (i >= 0)
                    func_0043CA48(o, i, name);
            }
            func_00447D00(h, n);
        } else {
            func_0043CA48(o, -1, D_00601488);
        }
        break;
    case 25:
        func_00447D00(h, n);
        func_0043CB88(o);
        break;
    case 26: {
        int k = 0;
        if (n != 0)
            k = (int)func_0043E0B0(ITEM(h));
        func_00447D00(h, n);
        func_0043CF10(o, k);
        break;
    }
    case 27:
        if (n != 0) {
            ValRaw c;
            func_0043D3B8((Val *)&c, ITEM(h));
            func_0043CFA0(o, &c);
            func_00447D00(h, n);
        } else {
            ValRaw c;
            c.a = 1;
            func_0043CFA0(o, &c);
        }
        break;
    }
    return Val();
}
