struct VEntry { short delta, index; int (*fn)(void *); };
struct Value { int first; VEntry *vt; };
struct Vec4 { int x,y,z,w; };
struct Data { char pad[0x119C]; Vec4 v; };
struct Input { char pad[0x10]; Data *data; };
struct Handle { void *p; char pad[12]; };
extern "C" void func_0015A690(Handle *, int) throw();
extern "C" void func_0015A6E8(Handle *, void *) throw();
extern "C" void func_002931C8(Handle *, int);
extern "C" void func_00293220(Handle *, void *);
extern "C" void func_002944D0(Handle *, void *, Handle *);
extern "C" void func_00295180(Handle *);
extern "C" Value **func_00295260(Handle *, int);
extern "C" void func_0029CEF0(Handle *, int);
extern "C" void func_0029EA18(Handle *, int);
extern "C" void func_002A75A8(Handle *, int);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
static inline int get(Handle *h, int i) {
    Value *p = *func_00295260(h, i);
    VEntry *v = (VEntry *)((char *)p->vt + 0x68);
    return v->fn((char *)p + v->delta);
}
static inline void store(Handle *p, const Vec4 *v) {
    ((Input *)p->p)->data->v = *v;
    func_0015A690(p, 2);
}
extern "C" void func_00164160(void **ret, void *input, int n, void *arg) {
    union { Vec4 v; Handle h; } a;
    Handle b,c,d,e,f,g,h;
    if (n > 0) {
        func_00293220(&b, arg);
        a.v.x = get(&b, 0);
        a.v.y = get(&b, 1);
        a.v.z = get(&b, 2);
        a.v.w = get(&b, 3);
        func_0015A6E8(&c, input);
        store(&c, &a.v);
        func_002931C8(&b, 2);
        return;
    }
    func_0015A6E8(&a.h, input);
    Data *data = ((Input *)a.h.p)->data;
    func_0015A690(&a.h, 2);
    func_00295180(&a.h);
    Vec4 *v = &data->v;
    Handle *dest = &d;
    { void *p = a.h.p;
    func_0029EA18(&e, v->x);
    func_002944D0(dest, p, &e);
    func_002A75A8(dest, 2);
    func_0029CEF0(&e, 2);
    }
    { void *p = a.h.p;
    func_0029EA18(&f, v->y);
    func_002944D0(dest, p, &f);
    func_002A75A8(dest, 2);
    func_0029CEF0(&f, 2);
    }
    { void *p = a.h.p;
    func_0029EA18(&g, v->z);
    func_002944D0(dest, p, &g);
    func_002A75A8(dest, 2);
    func_0029CEF0(&g, 2);
    }
    { void *p = a.h.p;
    func_0029EA18(&h, v->w);
    func_002944D0(dest, p, &h);
    func_002A75A8(dest, 2);
    func_0029CEF0(&h, 2);
    }
    if (ret != &a.h.p) {
        void *p = a.h.p;
        if (p) func_002C0FE8(p);
        if (*ret) func_002C1050(*ret);
        *ret = p;
    }
    func_002931C8(&a.h, 2);
}
