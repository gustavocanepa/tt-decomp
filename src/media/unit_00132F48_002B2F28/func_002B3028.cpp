/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VE { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VO { char pad[4]; VE *vtbl; };
struct Thing { int x; };
struct H { Thing *p; int pad[3]; };
struct Stk { char pad[0x8]; s32 *arr; char pad2[8]; s32 count; };
struct Ctx { char pad[0x2C]; Stk *stk; };
typedef void (Thing::*PMF)(H *, H *, int, void *);
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

static inline Thing *deref(H *h) { return h->p; }

static inline void assign(s32 *p, H *src) {
    if (p != (s32 *)src) {
        s32 newVal = *(s32 *)src;
        if (newVal != 0) func_002C0FE8(newVal);
        s32 oldVal = *p;
        if (oldVal != 0) func_002C1050(oldVal);
        *p = newVal;
    }
}

extern "C" void func_002B3028(Self *self, Ctx *c) {
    H h0;
    H h1;
    s32 *a = pop(c->stk);
    s32 *b = pop(c->stk);
    func_002A7A30(&h0);
    vcall((char *)*b, 0xA0, &h0);
    func_002A7A30(&h1);
    (deref(&h0)->*(self->pmf))(&h1, &h0, 1, a);
    vcall((char *)*b, 0xA8, &h1);
    Stk *s = c->stk;
    s32 *p = s->arr + s->count;
    assign(p, &h1);
    s->count = s->count + 1;
    func_002A75A8(&h1, 2);
    func_002A75A8(&h0, 2);
}
