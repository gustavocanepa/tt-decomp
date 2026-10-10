typedef int s32;

struct Str { char *p; };
extern char D_005F14D8[];
extern "C" void func_002AA210(const char *);

extern "C" void func_002AB6F0(Str *s) {
    char *d = s->p;
    s32 n = ((s32 *)d)[-4];
    const char *c;
    if (n == 0) {
        c = D_005F14D8;
    } else {
        d[n] = 0;
        c = s->p;
    }
    func_002AA210(c);
}
