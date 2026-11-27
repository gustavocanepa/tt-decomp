/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; int (*fn)(void *, void *, int); };
struct Entry3 { short delta, index; int (*fn)(void *, void *, int); };
struct Child { char pad[0x30]; Entry *vt; };
struct Arg { char pad[8]; Child *child; };
struct Self { char pad[0xA4]; Entry3 *vt; };
static inline int body(Self *self, int value, Arg *arg, int flag) {
    if (flag) {
        flag = (int)arg->child;
        Child *p = (Child *)flag;
        if (p) {
            Entry *e = (Entry *)((char *)p->vt + 0x20);
            return e->fn((char *)p + e->delta, arg, value);
        }
    }
    Entry3 *e = (Entry3 *)((char *)self->vt + 0x98);
    return e->fn((char *)self + e->delta, arg, value);
}
extern "C" int func_0047D588(Self *self, Arg *arg, int value, int flag) {
    return body(self, value, arg, flag);
}
