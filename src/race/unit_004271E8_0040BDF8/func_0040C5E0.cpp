typedef int s32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;

struct Global;
extern Global D_00585A30;

struct Info {
    char pad0[0x12];
    u8 f12;
    u8 f13;
    u8 f14;
    char pad15[0xB];
};

struct Obj {
    char pad0[0x40];
    s64 id;
    char pad48[0xE6];
    u8 f12E;
};

extern "C" s32 func_0040B980(Global *g, s64 id);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" u8 func_0040CDD0(Obj *self, s32 a, s32 b, s32 c);

extern "C" s32 func_0040C5E0(Obj *self) {
    s64 id = self->id;
    if (func_0040B980(&D_00585A30, id) == 0) {
        return 0;
    }
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_00585A30, id, &info);
    self->f12E = func_0040CDD0(self, info.f12, info.f14, info.f13);
    return 1;
}
