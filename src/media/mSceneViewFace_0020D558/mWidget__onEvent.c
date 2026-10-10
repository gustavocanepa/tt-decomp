struct VEntry { short delta; short index; int (*fn)(void *, int, void *); };
struct Obj { int a; struct VEntry *vtbl; };
extern int func_00526860(const char *, ...);
int mWidget__onEvent(void *ctx, int arg, struct Obj *o)
{
    struct VEntry *e = &o->vtbl[55];
    int r = e->fn((char *)o + e->delta, arg, ctx);
    func_00526860("status %s\n", r == 0 ? "CONTINUE" : r == 2 ? "FILTER" : "STOP");
    return r;
}
