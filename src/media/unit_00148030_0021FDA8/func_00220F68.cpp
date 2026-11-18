/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Handle { void *p; char pad[12]; };
extern "C" void func_002209C8(void *, void *) throw();
extern "C" void func_00220970(void *, int) throw();
extern "C" void func_0029CF48(void *, void *);
extern "C" int func_0029E9F0(void *);
extern "C" void func_0029CEF0(void *, int);
extern "C" int func_00223A08(void *, int);
extern "C" void func_001B7E38(void *, int);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
extern "C" void func_001B6EB0(void *, int);
static inline void *get(Handle *h) { return h->p; }
static inline void assign(Handle *out, const Handle *src) {
    if (out != src) {
        void *p = src->p;
        if (p) func_002C0FE8(p);
        if (out->p) func_002C1050(out->p);
        out->p = p;
    }
}
extern "C" void func_00220F68(Handle *out, void *src, int n, void *arg) {
    Handle copy;
    Handle temp;
    func_002209C8(&copy, src);
    int index = -1;
    if (n > 0) {
        func_0029CF48(&temp, arg);
        index = func_0029E9F0(get(&temp));
        func_0029CEF0(&temp, 2);
    }
    func_001B7E38(&temp, func_00223A08(copy.p, index));
    assign(out, &temp);
    func_001B6EB0(&temp, 2);
    func_00220970(&copy, 2);
}
