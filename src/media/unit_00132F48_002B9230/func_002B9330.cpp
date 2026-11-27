/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Thing { int x; };
struct H { Thing *p; int pad[3]; };
struct Stk { char pad[0x8]; s32 *arr; char pad2[8]; s32 count; };
struct Ctx { char pad[0x2C]; Stk *stk; };
typedef void (Thing::*PMF)(H *, s32 *, int, int);
struct Self { char pad[0xC]; PMF pmf; };
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_002A7A30(void *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

static inline s32 *pop(Stk *s) {
    s32 n = s->count - 1;
    s32 *a = s->arr;
    s->count = n;
    return a + n;
}

static inline Thing *deref(s32 *b) { return (Thing *)*b; }

extern "C" void func_002B9330(Self *self, Ctx *c) {
    H h0;
    H *ph0 = &h0;
    s32 *b = pop(c->stk);
    func_002A7A30(ph0);
    (deref(b)->*(self->pmf))(&h0, b, 0, 0);
    Stk *s = c->stk;
    s32 *p = s->arr + s->count;
    if (p != (s32 *)&h0) {
        s32 newVal = *(s32 *)&h0;
        if (newVal != 0) func_002C0FE8(newVal);
        s32 oldVal = *p;
        if (oldVal != 0) func_002C1050(oldVal);
        *p = newVal;
    }
    s->count = s->count + 1;
    func_002A75A8(&h0, 2);
}
