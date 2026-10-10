struct Obj { void *root; };
struct Count { int n; int max; };
typedef int (*Cb)(void *, void *);
extern "C" int func_004C7B80(void *, void *);
extern "C" int func_004C7A88(void *, void *);
extern "C" void func_004C73F8(void *root, Obj *o, Cb visit, Count *c, Cb filter);

extern "C" int func_004C7BA8(Obj *o, int filtered)
{
    Count c;
    c.n = 0;
    c.max = 0x7FFFFFFF;
    if (filtered)
        func_004C73F8(o->root, o, func_004C7B80, &c, func_004C7A88);
    else
        func_004C73F8(o->root, o, func_004C7B80, &c, 0);
    return c.n;
}
