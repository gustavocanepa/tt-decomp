typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
};

extern Rep D_005A4C58;

extern "C" char *strobe__toUpper(Rep *src);
extern "C" s32 func_004A8368(const char *s);
extern "C" void *func_00550E18(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" void *func_00448190(void *m, Str *k);
extern "C" s32 func_0043D3B8(void *a, void *b);
extern "C" void func_004A45D0(s32 p);

extern "C" void *func_0044B088(void *arg0, void *arg1) {
    Str s;
    Str *ps = &s;
    const char *src = "THIS";
    Rep *r = &D_005A4C58;
    char *d = (char *)(r + 1);
    if (r->sel != 0) {
        d = strobe__toUpper(r);
    } else {
        r->ref++;
    }
    ps->p = d;
    func_00550E18(ps, 0, -1, src, func_004A8368(src));
    func_0043D3B8(arg0, func_00448190(arg1, &s));
    {
        Rep *q = (Rep *)(s.p - 0x10);
        if (--q->ref == 0) {
            func_004A45D0((s32)q);
        }
    }
    return arg0;
}
