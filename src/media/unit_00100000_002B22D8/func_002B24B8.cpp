/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Obj;
struct VGet { short delta, index; void (*fn)(void *, s32, void *); };
struct Obj { s32 pad0; char *vt; };
struct Stk { char pad0[0x8]; Obj **arr; char pad1[8]; s32 top; };
struct A1 { char pad0[0x2C]; Stk *stk; };
struct A0 { char pad0[8]; s32 cnt; };

extern "C" void func_002931C8(void *arg0, int arg1);
extern "C" void *func_002951D0(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(void *p);
extern "C" void func_002C1050(void *p);

extern "C" void func_002B24B8(A0 *arg0, A1 *arg1) {
    Obj *h;
    s32 i = 0;
    Stk *st;
    Obj **d;

    func_002951D0(&h, arg0->cnt);
    if (arg0->cnt > 0) {
        Obj *o = h;
        do {
            Stk *t = arg1->stk;
            VGet *g = (VGet *)(o->vt + 0x90);
            void *adjusted = (char *)o + g->delta;
            t->top = t->top - 1;
            g->fn(adjusted, arg0->cnt - i - 1, t->arr + t->top);
            i++;
            o = h;
        } while (i < arg0->cnt);
    }
    st = arg1->stk;
    d = st->arr + st->top;
    if (d != &h) {
        Obj *p = h;
        if (p != 0) {
            func_002C0FE8(p);
        }
        if (*d != 0) {
            func_002C1050(*d);
        }
        *d = p;
    }
    st->top = st->top + 1;
    func_002931C8(&h, 2);
}
