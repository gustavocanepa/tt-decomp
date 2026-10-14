typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Rep { int len; int cap; int ref; int sel; };
struct Str { char *p; };
struct Obj { char pad0[0xA]; u16 hA; const u8 *sC; };
struct Obj2 { char pad0[8]; int f8; };
extern char D_005A4C58[];
extern "C" char *strobe__toUpper(void *);
extern "C" int func_004A8368(const char *);
extern "C" void *func_00550E18(void *, u32, u32, const char *, u32);
extern "C" void func_00447D48(void *);
extern "C" void *func_00448190(void *, void *);
extern "C" void *func_0043D3E0(void *, void *);
extern "C" void func_00447CD8(void *);
extern "C" void func_004A45D0(void *);

extern "C" void func_00440FC0(Obj *a, void *m, Obj2 *c, u32 count) {
    u32 i = 0;
    const u8 *s = a->sC;
    if (count == 0) return;
    do {
        if (i < a->hA) {
            Str tmp;
            Str *ps = &tmp;
            Rep *g = (Rep *)D_005A4C58;
            char *r;
            if (g->sel != 0) {
                r = strobe__toUpper(g);
            } else {
                r = (char *)g + 0x10;
                g->ref++;
            }
            ps->p = r;
            func_00550E18(ps, 0, (u32)-1, (const char *)s, func_004A8368((const char *)s));
            func_00447D48(&tmp);
            void *v = func_00448190(m, &tmp);
            func_0043D3E0(v, (void *)(c->f8 - 8));
            int ch;
            do {
                ch = *s++;
            } while (ch != 0);
            Rep *q = (Rep *)(tmp.p - 0x10);
            if (--q->ref == 0) func_004A45D0(q);
        }
        func_00447CD8(c);
        i++;
    } while (i < count);
}
