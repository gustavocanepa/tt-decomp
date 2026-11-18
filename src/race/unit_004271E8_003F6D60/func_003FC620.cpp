struct N { int v[3]; };
struct S { void *p; N n; };
extern "C" void func_0029CEF0(void *, int);
extern "C" void func_0029EA18(void *, void *);
extern "C" void func_002A75A8(void *, int);
extern "C" void func_002A7A30(void *);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
extern "C" int func_0028FF28(void *, void *, const char *, int, void *);
extern "C" void func_004F8588(void *, const char *, void *) throw();

extern "C" void func_003FC620(void *arg0, void *arg1, void *arg2) {
    S a;
    S b;
    func_002A7A30(&a);
    S *pb = &b;
    func_0029EA18(pb, arg2);
    if (&a != pb) {
        void *t = pb->p;
        if (t) func_002C0FE8(t);
        if (a.p) func_002C1050(a.p);
        a.p = t;
    }
    func_0029CEF0(pb, 2);
    if (func_0028FF28(arg0, arg1, "getUsingLanguage", 1, &a)) {
    } else {
        func_004F8588(arg0, "JP", arg1);
    }
    if ((void *)&a != (void *)&a.n)
        func_002A75A8(&a, 2);
}
