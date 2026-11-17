/* compiler: ee-gcc2.96-no-strict-aliasing */
/*
 * strobe::ActionInstance::doAction (GT HD name; behaviour inferred): the bytecode interpreter of
 * the game's Flash-style UI player. It runs `len` bytes of SWF actions from `pc` on the value stack
 * of the animation instance (+0x164) and returns the value of a Return action (0x3E), or
 * undefined at an End action (0x00) or the end of the code. Locals: the four action registers and
 * a stack of up to eight With blocks (object plus end address).
 *
 * Actions below 0x80 have no payload (play/stop/frame control, arithmetic and comparisons, string
 * and type conversion, variables, members, function and method calls, object creation); from 0x80
 * on a 16-bit length follows (GotoFrame, ConstantPool, Push, StoreRegister, DefineFunction, If,
 * Jump, With). Unknown actions are only reported through the debug printf.
 *
 * Source forms that decide the code (see knowledge/attempts.jsonl, 00481880):
 * - String has the library's copy constructor: it makes the class BLKmode, so its temporaries get
 *   16-byte stack slots like retail's; its constructor nests Rep::grab / assign / replace as
 *   bastring.h does.
 * - Any's copy constructor and operator= are out-of-line members (func_0043D3B8, func_0043D3E0):
 *   their arguments are then evaluated last-first, as in retail.
 * - Calls whose result is only pushed or passed on are written as one expression with
 *   temporaries bound to reference parameters (result slot first, then the argument slots).
 * - Type tests are inline bool predicates (xori compares); the With lookup of CallFunction is an
 *   inline function returning Any (copy into the caller's variable).
 * - Trace (0x26) is a case of its own (trace, pop): falling through into Pop changes the order of
 *   its printf arguments.
 */
#include "types.h"

/* ---- the script value (strobe::Any) ---- */
struct Any;
extern "C" void func_0043D3B8(Any *self, const Any *src);
extern "C" Any *func_0043D3E0(Any *self, const Any *src);
extern "C" void func_0043D510(Any *self);
extern "C" void func_0043D630(Any *self);
extern "C" void func_0043D658(Any *self);
extern "C" void func_0043D688(Any *self);
extern "C" void func_0043D738(Any *self, const char *s);
extern "C" void func_0043D780(Any *self, s32 b);
extern "C" void func_0043D7C8(Any *self, f32 n);
extern "C" void func_0043D810(Any *self, s32 i);
extern "C" void func_0043D838(Any *self, const u8 *body, s32 size, s32 nargs, const u8 *args, void *frame, void *pool);
extern "C" const char *strobe__Any__toString(Any *self); /* toString */
extern "C" f32 func_0043E0B0(Any *self); /* toNumber */
extern "C" s32 func_0043E0F8(Any *self); /* toBoolean */
extern "C" const char *strobe__Any__typeOf(Any *self);
extern "C" void func_0043F408(Any *self, s32 radix);

struct Any {
    s32 type;
    union {
        s32 i;
        f32 n;
        void *p;
    } u;
    Any() : type(1) {}
    Any(f32 n) : type(6) { u.n = n; }
    Any(const Any &o) __asm__("func_0043D3B8");
    ~Any() { func_0043D510(this); }
    Any &operator=(const Any &o) __asm__("func_0043D3E0");
    bool isUndefined() const { return type == 1; }
    bool isNotFound() const { return type == 2; }
    bool isObject() const { return type == 7; }
    bool isFunction() const { return type == 13; }
    bool isPrimitive() const { return (u32)(type - 3) < 2; }
};

/* ---- the string (libstdc++ v2 basic_string, second instantiation) ---- */
struct Rep;
extern "C" char *strobe__toUpper(Rep *rep);
struct Rep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    char *clone() { return strobe__toUpper(this); }
    char *grab() {
        if (selfish)
            return clone();
        ++ref;
        return data();
    }
};
extern Rep D_005A4C58;
extern char D_00601E30[];
struct String;
extern "C" String *func_00550E18(String *s, u32 pos, u32 n1, const char *src, u32 n2);
extern "C" u32 func_004A8368(const char *s);
extern "C" void func_004A45D0(Rep *rep);
extern "C" void func_00447D48(String *s); /* upper-cases the name */

struct String {
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    String(const String &o) : dat(o.rep()->grab()) {}
    String(const char *s) : dat(D_005A4C58.grab()) { assign(s); }
    ~String() {
        Rep *r = rep();
        if (--r->ref == 0)
            func_004A45D0(r);
    }
    String &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_00550E18(this, pos, n1, s, n2); }
    String &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String &assign(const char *s) { return assign(s, func_004A8368(s)); }
    u32 length() const { return rep()->len; }
    const char *c_str() {
        if (length() == 0)
            return D_00601E30;
        dat[length()] = 0;
        return dat;
    }
};

/* ---- interpreter state ---- */
struct ValStack {
    Any *start;
    Any *pad;
    Any *finish;
    Any *top() { return finish - 1; }
};
extern "C" void func_00447C80(ValStack *stack, const Any &v); /* push */
extern "C" void func_00447CD8(ValStack *stack); /* pop */
extern "C" void func_00447D00(ValStack *stack, s32 n); /* pop n */

struct String;
extern "C" s32 func_0043E388(Any *obj, String *name, Any *value, s32 create); /* obj.name = value */
struct WithEntry {
    Any obj;
    const u8 *end;
};
struct WithStack;
extern "C" s32 func_0056C9C0(WithStack *ws, const u8 *pc);
struct WithStack {
    WithEntry e[8];
    s32 depth;
    WithStack() : depth(-1) {}
    WithStack *active() { return depth < 0 ? 0 : this; }
    s32 setVariable(String &name, Any &v) {
        for (s32 i = depth; i >= 0; i--)
            if (func_0043E388(&e[i].obj, &name, &v, 0))
                return 1;
        return 0;
    }
    s32 check(const u8 *pc) {
        s32 i = depth;
        if (i < 0)
            return 0;
        if (!(pc < e[i].end)) {
            depth = i - 1;
            return func_0056C9C0(this, pc);
        }
        return 1;
    }
};

extern "C" s32 func_00448418(const u8 **p) throw(); /* reads a 16-bit value and advances */
extern "C" s32 func_00448440(const u8 **p); /* reads a 32-bit value and advances */
extern "C" void func_004A6448(const char *fmt, ...); /* debug printf */
extern "C" f32 func_0043C9F8(char *anim);
extern "C" void *func_0043C9E8(char *anim);
extern "C" Any func_0044B088(void *self); /* the instance's target movie clip */
extern "C" Any func_0043E890(const Any &obj, const String &name, void *self, s32 nargs, void *pool, char *anim); /* calls obj.name(nargs arguments from the stack) */
extern "C" Any func_0043E4E0(Any *fn, void *self, s32 nargs, void *pool, char *anim);
extern "C" Any func_0043D2E8(String *name, char *anim);
extern "C" Any func_00447EF0(void *cb, String *name, s32 nargs, ValStack *stack);
extern "C" Any func_0043E148(const Any &obj, const String &name); /* obj.name */
extern "C" Any func_0044B2B0(void *self, String *name, void *frame, WithStack *ws, char *anim);
extern "C" void func_0043D990(Any *result, Any *source, void *self, s32 nargs, void *pool, char *anim);
extern "C" s32 func_0043E388(Any *obj, String *name, Any *value, s32 create);
extern "C" Any *func_00447FB0(void *frame, String *name); /* variable slot or 0 */
extern "C" s32 func_00448000(void *frame, String *name);
extern "C" Any *func_00448190(void *frame, String *name); /* variable slot, created when missing */
extern "C" s32 func_00447738(void *vars, String *name, Any *value);
extern "C" void func_0044B4C8(void *self, const char *path, void *frame, WithStack *ws, char *anim, const char **var, Any *target);
extern "C" void func_0044C0E8(void *pool, const u8 *data);
extern "C" const char *func_0044C218(void *pool, s32 index);
extern "C" void *func_0043DEE8(s32 v);
extern "C" void func_0043E9E8(Any *v, ValStack *stack);
extern "C" void func_0043EA30(Any *a, Any *b);
extern "C" s32 func_0043EB78(Any *a, Any *b);
extern "C" s32 func_0043EC50(Any *a, Any *b);
extern "C" s32 func_0043ED48(Any *a, Any *b);
extern "C" s32 func_0043EDC8(Any *a, Any *b);
extern "C" s32 func_0043EEA0(Any *a, Any *b);
extern "C" void func_0043EED0(Any *a, Any *b);
extern "C" void func_0043EF20(Any *a, Any *b);
extern "C" void func_0043EF70(Any *a, Any *b);
extern "C" void func_0043EFC8(Any *a, Any *b);
extern "C" void func_0043F050(Any *a);
extern "C" void func_0043F0D0(Any *a, Any *b);
extern "C" void func_0043F130(Any *a, Any *b);
extern "C" void func_0043F190(Any *a, Any *b);
extern "C" void func_0043F1F0(Any *a, Any *b);
extern "C" void func_0043F250(Any *a, Any *b);
extern "C" void func_0043F2B0(Any *a, Any *b);
extern "C" void func_0043F310(Any *a, Any *b);
extern "C" void func_0043F398(Any *a);
extern "C" void func_0043F3D0(Any *a);

extern char D_00601DF8[], D_00601E00[], D_00601E08[], D_00601E18[], D_00601E28[];
extern char D_00601E38[], D_00601E48[], D_00601E78[], D_00601E88[], D_00601EC0[];
extern char D_00601EF8[], D_00601F00[], D_00601F10[], D_00601F30[], D_00601F40[];
extern const char *D_00586930[];


static inline Any findInWith(WithStack &ws, const String &name, void *self, u32 nargs, void *pool, char *anim) {
    Any fn;
    for (s32 i = ws.depth; i >= 0; i--) {
        fn = func_0043E890(ws.e[i].obj, name, self, nargs, pool, anim);
        if (!fn.isNotFound())
            return fn;
    }
    func_0043D658(&fn);
    return fn;
}

struct Action {
    char pad[0x14];
    void *vars;
};

extern "C" Any strobe__ActionInstance__doAction(Action *self, const u8 *pc, s32 len, void *pool, void *frame, char *anim) {
    Any regs[4];
    WithStack withs;
    ValStack *stack = *(ValStack **)(anim + 0x164);
    const u8 *end = pc + len;

    while (pc < end) {
        u8 op = *pc++;
        if (op == 0)
            return Any();
        if ((s8)op >= 0) {
            switch (op) {
            case 0x06: {
                func_0043E890(func_0044B088(self), String(D_00601DF8), self, 0, pool, anim);
                break;
            }
            case 0x07: {
                func_0043E890(func_0044B088(self), String(D_00601E00), self, 0, pool, anim);
                break;
            }
            case 0x04: {
                func_0043E890(func_0044B088(self), String(D_00601E08), self, 0, pool, anim);
                break;
            }
            case 0x05: {
                func_0043E890(func_0044B088(self), String(D_00601E18), self, 0, pool, anim);
                break;
            }
            case 0x34:
                func_00447C80(stack, Any((f32)(s32)(func_0043C9F8(anim) * 1000.0f)));
                break;
            case 0x26:
                func_004A6448(D_00601E28, strobe__Any__toString(stack->top()));
                func_00447CD8(stack);
                break;
            case 0x17:
                func_00447CD8(stack);
                break;
            case 0x0A:
            case 0x47: {
                Any b(*stack->top());
                func_00447CD8(stack);
                func_0043EA30(stack->top(), &b);
                break;
            }
            case 0x0B: {
                Any b(*stack->top());
                func_00447CD8(stack);
                func_0043EED0(stack->top(), &b);
                break;
            }
            case 0x0C: {
                Any b(*stack->top());
                func_00447CD8(stack);
                func_0043EF20(stack->top(), &b);
                break;
            }
            case 0x0D: {
                Any b(*stack->top());
                func_00447CD8(stack);
                func_0043EF70(stack->top(), &b);
                break;
            }
            case 0x48: {
                Any b(*stack->top());
                func_00447CD8(stack);
                Any *a = stack->top();
                func_0043D780(a, func_0043EB78(a, &b));
                break;
            }
            case 0x0E:
            case 0x49: {
                Any b(*stack->top());
                func_00447CD8(stack);
                Any *a = stack->top();
                func_0043D780(a, func_0043EDC8(a, &b));
                break;
            }
            case 0x13: {
                Any b(*stack->top());
                strobe__Any__toString(&b);
                func_00447CD8(stack);
                strobe__Any__toString(stack->top());
                Any *a = stack->top();
                func_0043D780(a, func_0043EDC8(a, &b));
                break;
            }
            case 0x66: {
                Any b(*stack->top());
                func_00447CD8(stack);
                Any *a = stack->top();
                func_0043D780(a, func_0043EEA0(a, &b));
                break;
            }
            case 0x67: {
                Any b(*stack->top());
                func_00447CD8(stack);
                Any *a = stack->top();
                func_0043D780(a, func_0043EC50(a, &b));
                break;
            }
            case 0x68: {
                Any b(*stack->top());
                func_00447CD8(stack);
                Any *a = stack->top();
                func_0043D780(a, func_0043ED48(a, &b));
                break;
            }
            case 0x3F: {
                Any b(*stack->top());
                func_00447CD8(stack);
                func_0043EFC8(stack->top(), &b);
                break;
            }
            case 0x60: {
                Any b(*stack->top());
                func_00447CD8(stack);
                func_0043F0D0(stack->top(), &b);
                break;
            }
            case 0x10: {
                Any b(*stack->top());
                func_00447CD8(stack);
                func_0043F130(stack->top(), &b);
                break;
            }
            case 0x61: {
                Any b(*stack->top());
                func_00447CD8(stack);
                func_0043F190(stack->top(), &b);
                break;
            }
            case 0x12:
                func_0043F050(stack->top());
                break;
            case 0x63: {
                Any b(*stack->top());
                func_00447CD8(stack);
                func_0043F250(stack->top(), &b);
                break;
            }
            case 0x64: {
                Any b(*stack->top());
                func_00447CD8(stack);
                func_0043F2B0(stack->top(), &b);
                break;
            }
            case 0x65: {
                Any b(*stack->top());
                func_00447CD8(stack);
                func_0043F310(stack->top(), &b);
                break;
            }
            case 0x62: {
                Any b(*stack->top());
                func_00447CD8(stack);
                func_0043F1F0(stack->top(), &b);
                break;
            }
            case 0x51:
                func_0043F3D0(stack->top());
                break;
            case 0x50:
                func_0043F398(stack->top());
                break;
            case 0x4C:
                func_00447C80(stack, *stack->top());
                break;
            case 0x4D: {
                Any a(*stack->top());
                func_00447CD8(stack);
                Any b(*stack->top());
                func_00447CD8(stack);
                func_00447C80(stack, a);
                func_00447C80(stack, b);
                break;
            }
            case 0x3D: {
                String name(strobe__Any__toString(stack->top()));
                func_00447D48(&name);
                func_00447CD8(stack);
                u32 nargs = (u32)func_0043E0B0(stack->top());
                func_00447CD8(stack);
                if (withs.check(pc - 1)) {
                    Any r = findInWith(withs, name, self, nargs, pool, anim);
                    if (!r.isNotFound()) {
                        func_00447C80(stack, r);
                        break;
                    }
                }
                {
                    Any *f = func_00447FB0(frame, &name);
                    if (f != 0 && f->isFunction()) {
                        Any r = func_0043E4E0(f, self, nargs, pool, anim);
                        func_00447C80(stack, r);
                        break;
                    }
                }
                {
                    Any fn;
                    fn = func_0043E890(func_0044B088(self), name, self, nargs, pool, anim);
                    if (!fn.isNotFound()) {
                        func_00447C80(stack, fn);
                        break;
                    }
                    fn = func_0043D2E8(&name, anim);
                    if (fn.isUndefined()) {
                        Any r = func_00447EF0(func_0043C9E8(anim), &name, nargs, stack);
                        func_00447C80(stack, r);
                    } else {
                        Any r = func_0043E4E0(&fn, self, nargs, pool, anim);
                        func_00447C80(stack, r);
                    }
                }
                break;
            }
            case 0x3E: {
                Any v(*stack->top());
                func_00447CD8(stack);
                return v;
            }
            case 0x52: {
                String name(strobe__Any__toString(stack->top()));
                func_00447D48(&name);
                func_00447CD8(stack);
                Any obj(*stack->top());
                func_00447CD8(stack);
                u32 nargs = (u32)func_0043E0B0(stack->top());
                func_00447CD8(stack);
                Any r = func_0043E890(obj, name, self, nargs, pool, anim);
                func_00447C80(stack, r);
                break;
            }
            case 0x40: {
                String name(strobe__Any__toString(stack->top()));
                func_004A6448(D_00601E38, name.c_str());
                func_00447D48(&name);
                func_00447CD8(stack);
                u32 nargs = (u32)func_0043E0B0(stack->top());
                func_00447CD8(stack);
                Any ctor = func_0044B2B0(self, &name, frame, &withs, anim);
                if (!ctor.isUndefined()) {
                    Any r;
                    func_0043D990(&r, &ctor, self, nargs, pool, anim);
                    func_00447C80(stack, r);
                } else {
                    func_004A6448(D_00601E48, name.c_str());
                    func_00447D00(stack, nargs);
                    Any r;
                    func_00447C80(stack, r);
                }
                break;
            }
            case 0x53: {
                String name(strobe__Any__toString(stack->top()));
                func_004A6448(D_00601E78, name.c_str());
                func_00447D48(&name);
                func_00447CD8(stack);
                Any obj(*stack->top());
                func_00447CD8(stack);
                u32 nargs = (u32)func_0043E0B0(stack->top());
                func_00447CD8(stack);
                Any ctor = func_0043E148(obj, name);
                if (!ctor.isUndefined()) {
                    Any r;
                    func_0043D990(&r, &ctor, self, nargs, pool, anim);
                    func_00447C80(stack, r);
                } else {
                    func_004A6448(D_00601E48, name.c_str());
                    func_00447D00(stack, nargs);
                    Any r;
                    func_00447C80(stack, r);
                }
                break;
            }
            case 0x42: {
                s32 n = (s32)func_0043E0B0(stack->top());
                func_00447CD8(stack);
                Any array;
                func_0043D688(&array);
                Any r;
                func_0043D990(&r, &array, self, n, pool, anim);
                func_00447C80(stack, r);
                break;
            }
            case 0x43: {
                s32 n = (s32)func_0043E0B0(stack->top());
                func_00447CD8(stack);
                Any proto;
                Any obj;
                func_0043D990(&obj, &proto, self, 0, pool, anim);
                for (s32 i = 0; i < n; i++) {
                    Any v(*stack->top());
                    func_00447CD8(stack);
                    String name(strobe__Any__toString(stack->top()));
                    func_00447D48(&name);
                    func_00447CD8(stack);
                    func_0043E388(&obj, &name, &v, 1);
                }
                func_00447C80(stack, obj);
                break;
            }
            case 0x3C: {
                Any v(*stack->top());
                func_00447CD8(stack);
                String name(strobe__Any__toString(stack->top()));
                func_00447D48(&name);
                func_00447CD8(stack);
                *func_00448190(frame, &name) = v;
                break;
            }
            case 0x41: {
                String name(strobe__Any__toString(stack->top()));
                func_00447D48(&name);
                func_00448190(frame, &name);
                func_00447CD8(stack);
                break;
            }
            case 0x1C: {
                withs.check(pc - 1);
                const char *var;
                Any target;
                func_0044B4C8(self, strobe__Any__toString(stack->top()), frame, &withs, anim, &var, &target);
                func_00447CD8(stack);
                String name(var);
                func_00447D48(&name);
                if (target.isUndefined()) {
                    Any r = func_0044B2B0(self, &name, frame, &withs, anim);
                    func_00447C80(stack, r);
                } else {
                    Any r = func_0043E148(target, name);
                    func_00447C80(stack, r);
                }
                break;
            }
            case 0x1D: {
                Any v(*stack->top());
                func_00447CD8(stack);
                withs.check(pc - 1);
                const char *var;
                Any target;
                func_0044B4C8(self, strobe__Any__toString(stack->top()), frame, &withs, anim, &var, &target);
                func_00447CD8(stack);
                String name(var);
                func_00447D48(&name);
                if (target.isUndefined()) {
                    if (withs.active() && withs.setVariable(name, v))
                        break;
                    Any *slot = func_00447FB0(frame, &name);
                    if (slot != 0)
                        *slot = v;
                    else if (func_00447738(self->vars, &name, &v) == 0)
                        *func_00448190(self, &name) = v;
                } else {
                    func_0043E388(&target, &name, &v, 1);
                }
                break;
            }
            case 0x4E: {
                String name(strobe__Any__toString(stack->top()));
                func_00447D48(&name);
                func_00447CD8(stack);
                Any obj(*stack->top());
                func_00447CD8(stack);
                Any r = func_0043E148(obj, name);
                func_00447C80(stack, r);
                break;
            }
            case 0x4F: {
                Any v(*stack->top());
                func_00447CD8(stack);
                String name(strobe__Any__toString(stack->top()));
                func_00447D48(&name);
                func_00447CD8(stack);
                Any obj(*stack->top());
                func_00447CD8(stack);
                func_0043E388(&obj, &name, &v, 1);
                break;
            }
            case 0x22: {
                s32 index = (s32)func_0043E0B0(stack->top());
                func_00447CD8(stack);
                Any path(*stack->top());
                func_00447CD8(stack);
                Any target;
                const char *s = strobe__Any__toString(&path);
                if (*s == 0)
                    target = func_0044B088(self);
                else
                    func_004A6448(D_00601E88, s);
                if ((u32)index < 22)
                    func_00447C80(stack, func_0043E148(target, String(D_00586930[index])));
                else
                    func_00447C80(stack, Any());
                break;
            }
            case 0x23: {
                Any v(*stack->top());
                func_00447CD8(stack);
                s32 index = (s32)func_0043E0B0(stack->top());
                func_00447CD8(stack);
                Any path(*stack->top());
                func_00447CD8(stack);
                Any target;
                const char *s = strobe__Any__toString(&path);
                if (*s == 0)
                    target = func_0044B088(self);
                else
                    func_004A6448(D_00601EC0, s);
                if ((u32)index < 22) {
                    String name(D_00586930[index]);
                    func_0043E388(&target, &name, &v, 0);
                }
                break;
            }
            case 0x4A: {
                Any v(*stack->top());
                func_00447CD8(stack);
                if (v.isObject()) {
                    Any r = func_0043E890(v, String(D_00601EF8), self, 0, pool, anim);
                    Any n(func_0043E0B0(&r));
                    func_00447C80(stack, n);
                } else {
                    func_0043F408(&v, 10);
                    func_00447C80(stack, v);
                }
                break;
            }
            case 0x4B: {
                Any v(*stack->top());
                func_00447CD8(stack);
                if (v.isObject()) {
                    Any r = func_0043E890(v, String(D_00601F00), self, 0, pool, anim);
                    if (r.isPrimitive()) {
                        func_00447C80(stack, r);
                        break;
                    }
                }
                strobe__Any__toString(&v);
                func_00447C80(stack, v);
                break;
            }
            case 0x18: {
                Any v(*stack->top());
                func_00447CD8(stack);
                func_0043F408(&v, 10);
                func_0043D7C8(&v, (f32)(s32)func_0043E0B0(&v));
                func_00447C80(stack, v);
                break;
            }
            case 0x44: {
                Any *v = stack->top();
                func_0043D738(v, strobe__Any__typeOf(v));
                break;
            }
            case 0x55: {
                Any obj(*stack->top());
                func_00447CD8(stack);
                Any null;
                func_0043D630(&null);
                func_00447C80(stack, null);
                func_0043E9E8(&obj, stack);
                break;
            }
            default:
                func_004A6448(D_00601F10, op);
                break;
            }
        } else {
            s32 size = func_00448418(&pc);
            const u8 *p = pc;
            pc += size;
            switch (op) {
            case 0x81: {
                Any frameNo((f32)(func_00448418(&p) + 1));
                func_00447C80(stack, frameNo);
                func_0043E890(func_0044B088(self), String(D_00601F30), self, 1, pool, anim);
                break;
            }
            case 0x88:
                func_0044C0E8(pool, p);
                break;
            case 0x96:
                while (p < pc) {
                    u8 type = *p++;
                    Any v;
                    switch (type) {
                    case 0:
                        func_0043D738(&v, (const char *)p);
                        while (*p++ != 0)
                            ;
                        break;
                    case 1: {
                        s32 bits = func_00448440(&p);
                        func_0043D7C8(&v, *(f32 *)&bits);
                        break;
                    }
                    case 2:
                        func_0043D630(&v);
                        break;
                    case 3:
                        func_0043D510(&v);
                        break;
                    case 4:
                        v = regs[*p++];
                        break;
                    case 5:
                        func_0043D780(&v, *p++ != 0);
                        break;
                    case 6: {
                        u8 b[4];
                        s32 c;
                        c = *p++;
                        b[0] = c << 3;
                        b[1] = c >> 5;
                        c = *p++;
                        b[1] |= c << 3;
                        b[2] = c >> 5;
                        c = *p++;
                        b[2] |= (c & 0x1F) << 3;
                        b[3] = c >> 5;
                        c = *p++;
                        b[3] |= (c & 0xC0) | ((c & 7) << 3);
                        p += 3;
                        c = *p++;
                        b[0] |= c >> 5;
                        func_0043D7C8(&v, *(f32 *)b);
                        break;
                    }
                    case 7:
                        func_0043D810(&v, func_00448440(&p));
                        break;
                    case 8:
                        func_0043D738(&v, func_0044C218(pool, *p++));
                        break;
                    case 9:
                        func_0043D738(&v, func_0044C218(pool, func_00448418(&p)));
                        break;
                    }
                    func_00447C80(stack, v);
                }
                break;
            case 0x87: {
                Any &reg = regs[*p++];
                reg = *stack->top();
                break;
            }
            case 0x9B: {
                s32 anonymous = *p == 0;
                String name((const char *)p);
                func_00447D48(&name);
                s32 existing = 0;
                if (!anonymous)
                    existing = func_00448000(frame, &name);
                if (existing == 0) {
                    while (*p++ != 0)
                        ;
                    Any fn;
                    u32 nargs = func_00448418(&p);
                    const u8 *args = p;
                    u32 i;
                    for (i = 0; i < nargs; i++)
                        while (*p++ != 0)
                            ;
                    s32 bodySize = func_00448418(&p);
                    func_0043D838(&fn, pc, bodySize, nargs, args, frame, pool);
                    if (anonymous)
                        func_00447C80(stack, fn);
                    else
                        *func_00448190(frame, &name) = fn;
                    pc += bodySize;
                } else {
                    pc += *(u16 *)((char *)func_0043DEE8(existing) + 8);
                }
                break;
            }
            case 0x9D: {
                s32 cond = func_0043E0F8(stack->top());
                func_00447CD8(stack);
                if (!cond)
                    break;
            }
            case 0x99:
                pc += (s16)func_00448418(&p);
                break;
            case 0x94: {
                withs.check(pc);
                Any *obj = stack->top();
                const u8 *blockEnd = pc + func_00448418(&p);
                if (withs.depth < 7) {
                    withs.depth++;
                    withs.e[withs.depth].obj = *obj;
                    withs.e[withs.depth].end = blockEnd;
                }
                func_00447CD8(stack);
                break;
            }
            default:
                func_004A6448(D_00601F40, op, size);
                break;
            }
        }
    }
    return Any();
}
