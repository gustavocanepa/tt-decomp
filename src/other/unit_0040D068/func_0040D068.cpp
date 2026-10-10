typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Global;
extern Global D_00585A30;

struct Info {
    char pad0[0x6];
    u8 f6;
    char pad7[0x9];
};

struct Obj {
    char pad0[0xD0];
    s64 id;
};

extern "C" s32 func_0040B910(Global *g, s64 id, Info *info);
extern "C" s32 func_0040D170(Obj *self);

extern "C" s32 func_0040D068(Obj *self) {
    s32 r = 0;
    s64 id = self->id;
    if (id != -1) {
        Info info;
        func_0040B910(&D_00585A30, id, &info);
        r = info.f6;
    }
    if (func_0040D170(self)) {
        r += 4;
    }
    return r;
}
