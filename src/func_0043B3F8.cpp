struct Entry { char pad0[8]; unsigned short lim; unsigned short sub; char pad[0x24 - 0xC + 4]; };
struct Ctx;
extern "C" void func_0043B268(Ctx *) throw();
extern "C" void func_0043B320(Ctx *);
extern "C" void func_0043B388(Ctx *);
extern "C" void func_0043B768(Entry *, Ctx *, int, float);

extern "C" short *func_0043B3F8(Entry **tab, Ctx *c, int lim, short *cur, short *end, int x, float t) {
    while (cur != end) {
        Entry *e = *tab + *cur;
        if (lim < e->lim) return cur;
        if (e->sub != 0) func_0043B268(c);
        func_0043B768(e, c, x, t);
        if (e->sub != 0) {
            func_0043B320(c);
            cur = func_0043B3F8(tab, c, e->sub, cur + 1, end, x, t) - 1;
            func_0043B388(c);
        }
        cur++;
    }
    return end;
}
