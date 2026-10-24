/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { signed char type; char pad1[3]; short start; short end; };
struct Group {
    int x; char pad4[4]; unsigned short *src; char *out;
    char pad10[0x214 - 0x10]; volatile int count; Ent ents[1];
};
struct S { char pad0[4]; int n; char pad8[0x18]; char groups[1]; };
struct S2 { char pad0[0x85C]; int active; };
extern "C" char *func_004B4FE0(char *, const unsigned short *);
extern "C" void *func_004F64C4(void *, const void *, unsigned);
extern "C" unsigned short *func_0050E130(int);
extern "C" void func_0050E1A8(void *) throw();
static inline int count(Group *g) { return g->count; }
extern "C" void func_00486138(S *s, char **out, int limit, unsigned char fill) {
    int pos = 0, done = 0, i = 0;
    char *base = (char *)s + ((S2 *)s)->active * 0x41C;
    Group *g = (Group *)(base + 0x24);
    unsigned short *buf = func_0050E130(s->n * 2);
    int n = count(g);
    if (i < n) {
        Ent *e = g->ents;
        do {
            e++;
            i++;
            if (e[-1].type == 6) {
                done++;
                func_004F64C4((void *)(pos * 2 + (int)buf), (void *)(e[-1].start * 2 + (int)g->src), (e[-1].end - e[-1].start) * 2);
                buf[pos + (e[-1].end - e[-1].start)] = 0;
                pos += e[-1].end - e[-1].start;
                if (done >= limit) break;
            }
            n = count(g);
        } while (i < n);
    }
    func_004B4FE0(g->out, buf);
    *out = g->out;
    if (fill != 0) {
        for (int k = 0; ((unsigned char *)*out)[k] != 0; k++) {
            (*out)[k] = fill;
        }
    }
    func_0050E1A8(buf);
}
