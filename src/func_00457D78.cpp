/* compiler: ee-gcc2.96-nogcse */
struct Ent { short adj; short pad; void (*fn)(void *, int); };
struct VTab { char pad[8]; Ent e; };
struct A { char p[0x20]; VTab *v; };
struct B { char p[0x104]; VTab *v; };
extern "C" {
void func_00457EA0(void *);
void func_00459818(void *, int);
void func_0045A7C0(void *, int);
void func_0045A7C0_(void *, int);
int func_0050E1A8(void *) throw();
}
extern char D_005DA1D8[];
extern "C" int func_00457D78(char *o, int flags)
{
    char *base = o + 0xDE0;
    *(char **)(o + 0x11D0) = D_005DA1D8;
    func_00457EA0(o);
    if (base != (char *)-0x318) {
        char *t = o + 0x10F8;
        char *p = o + 0x11D0;
        if (t != p) {
            char *end = t;
            do {
                p -= 0x24;
                Ent *e = &((A *)p)->v->e;
                e->fn(p + e->adj, 2);
            } while (end != p);
        }
    }
    if (base != 0) {
        char *q = base + 0x318;
        if (base != q) {
            do {
                q -= 0x108;
                Ent *e = &((B *)q)->v->e;
                e->fn(q + e->adj, 2);
            } while (base != q);
        }
    }
    char *m = o + 8;
    func_00459818(o + 0xA88, 2);
    func_0045A7C0(m, 2);
    if (flags & 1) return func_0050E1A8(o);
}
