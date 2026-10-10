typedef int s32;
typedef long long s64;

struct Global;
extern Global D_00585A30;

struct Ref {
    s64 id;
    char pad8[0x18];
};

struct Info {
    char pad0[0x98];
    s64 f98;
    char padA0[0x30];
};

struct Obj {
    s64 id;
};

extern "C" s32 func_0040B980(Global *g, s64 id);
extern "C" s32 func_0040B910(Global *g, s64 id, void *info);

extern "C" s32 func_0040D0D0(Obj *self, s32 kind) {
    Ref r;
    func_0040B910(&D_00585A30, self->id, &r);
    if (r.id == -1 || func_0040B980(&D_00585A30, r.id) == 0) {
        return 0;
    }
    Info info;
    func_0040B910(&D_00585A30, r.id, &info);
    if (kind != 0x14) {
        return 0;
    }
    return info.f98 == -1;
}
