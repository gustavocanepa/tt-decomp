/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct H { struct Thing *p; int pad[3]; };
struct VE { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VE2 { s16 delta; s16 index; void (*fn)(H *, void *); };
struct VO { char pad[4]; VE *vtbl; };
struct Thing { int x; };
struct Stk { char pad[0x8]; s32 *arr; char pad2[8]; s32 count; };
struct Ctx { char pad[0x2C]; Stk *stk; };
typedef void (Thing::*PMF)(H *, H *, int, int);
struct Self { char pad[0xC]; PMF pmf; };
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_002A7A30(void *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

static inline s32 *pop(Stk *s) {
    return s->arr + --s->count;
}

static inline void vcall(char *o, int off, void *arg) {
    VE *e = (VE *)((char *)((VO *)o)->vtbl + off);
    e->fn(o + e->delta, arg);
}

static inline void vcallret(H *ret, char *o, int off) {
    VE2 *e = (VE2 *)((char *)((VO *)o)->vtbl + off);
    e->fn(ret, o + e->delta);
}

static inline Thing *deref(H *h) { return h->p; }

extern "C" void func_002B8EC8(Self *self, Ctx *c) {
    H h0;
    H h1;
    H h2;
    H *ph0 = &h0;
    s32 *b = pop(c->stk);
    func_002A7A30(ph0);
    vcall((char *)*b, 0xA0, &h0);
    vcallret(&h1, (char *)h0.p, 0x98);
    vcall((char *)*b, 0xA8, &h1);
    func_002A7A30(&h2);
    (deref(&h1)->*(self->pmf))(&h2, &h1, 0, 0);
    Stk *s = c->stk;
    s32 *p = s->arr + s->count;
    if (p != (s32 *)&h2) {
        s32 newVal = (s32)deref(&h2);
        if (newVal != 0) func_002C0FE8(newVal);
        s32 oldVal = *p;
        if (oldVal != 0) func_002C1050(oldVal);
        *p = newVal;
    }
    s->count = s->count + 1;
    func_002A75A8(&h2, 2);
    func_002A75A8(&h1, 2);
    func_002A75A8(&h0, 2);
}
