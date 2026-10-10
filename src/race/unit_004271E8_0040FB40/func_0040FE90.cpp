typedef int s32;

struct Mgr {
    char pad[0x1E0];
    s32 f1E0;
};

struct Rec {
    s32 a;
    s32 b;
    s32 name;
    s32 pad[5];
};

extern Mgr D_00585A38;
extern char D_005FBFD0[];
extern "C" s32 func_0040FED0(s32, Rec *);
extern "C" const char *func_00411D78(s32, s32);

extern "C" const char *func_0040FE90(s32 key) {
    Rec rec;
    const char *r;
    if (func_0040FED0(key, &rec) == 0)
        r = D_005FBFD0;
    else
        r = func_00411D78(D_00585A38.f1E0, rec.name);
    return r;
}
