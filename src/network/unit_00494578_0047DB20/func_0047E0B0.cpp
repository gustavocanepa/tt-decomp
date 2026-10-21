/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
struct Entry { short delta, index; void (*fn)(void *); };
struct Invoke { short delta, index; int (*fn)(void *, Obj *, int, int); };
struct Peer { char pad[0xA4]; Invoke *vt; };
struct Obj { char pad[0x38]; Peer *peer; char rest[0x6C]; Entry *vt; };
struct Temp { char data[0xAC]; };
extern "C" Obj *func_0047DAE8(Temp *, int) throw();
extern "C" void func_0047E910(Temp *);
extern "C" void func_0047E9C0(Temp *, int);
extern "C" void func_0047EE88(Obj *);
extern "C" int func_0047E0B0(int arg0, int arg1, int arg2) {
    Temp temp;
    int result = 0;
    func_0047E910(&temp);
    Obj *o = func_0047DAE8(&temp, arg0);
    if (o) {
        Peer *p = o->peer;
        Invoke *e = p->vt + 16;
        result = e->fn((char *)p + e->delta, o, arg1, arg2);
        Entry *f = o->vt + 3;
        f->fn((char *)o + f->delta);
        Entry *g = o->vt + 4;
        g->fn((char *)o + g->delta);
        func_0047EE88(o);
    }
    func_0047E9C0(&temp, 2);
    return result;
}
