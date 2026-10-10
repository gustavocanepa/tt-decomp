typedef int s32;

struct Res { s32 m0; s32 m4; s32 pad[2]; };

extern char D_005F2AD0[];
extern "C" void func_00424408(Res *, void *, char *);

static inline Res *find(Res *r) {
    s32 ok = r->m4 >= 0;
    return ok ? r : 0;
}

extern "C" s32 func_002DD020(void *a) {
    Res r;
    func_00424408(&r, a, D_005F2AD0);
    return find(&r) != 0;
}
