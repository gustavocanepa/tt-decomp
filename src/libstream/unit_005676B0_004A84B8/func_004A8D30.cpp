/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pred { int (*fn)(void *, int); void *arg; };
struct Callback { int (*fn)(void *, int); void *arg; };
struct Obj { Pred pred; Callback before, after; const char *name; int n; int size; int active; };
extern "C" void func_004A8F88(const char *, const char *, const char *, int, int);
extern "C" void func_004A8D30(Obj *p, int arg1, const char *arg2, const char *arg3) {
    if (p->pred.fn(p->pred.arg, arg1)) {
        Callback *c = &p->before;
        c->fn(c->arg, arg1);
        const char *name = p->name;
        if (name) func_004A8F88(arg2, name, arg3, p->size, p->n);
        c = &p->after;
        c->fn(c->arg, arg1);
    }
}
