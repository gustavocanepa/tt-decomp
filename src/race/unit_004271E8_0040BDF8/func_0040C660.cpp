typedef int s32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;

struct Global;
extern Global D_00585A30;

struct Info {
    char pad0[0x3];
    u8 f3;
    char pad4[0x2];
    u8 f6;
    u8 f7;
    char pad8[0x2];
    u8 fA;
    char padB[0x5];
};

struct Obj {
    char pad0[0x28];
    s64 id;
    char pad30[0xFF];
    u8 f12F;
    u8 f130;
};

extern "C" s32 func_0040B980(Global *g, s64 id);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" u8 func_0040CDD0(Obj *self, s32 a, s32 b, s32 c);

extern "C" s32 func_0040C660(Obj *self) {
    s64 id = self->id;
    if (func_0040B980(&D_00585A30, id) == 0) {
        return 0;
    }
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_00585A30, id, &info);
    self->f12F = func_0040CDD0(self, 1, info.f6, info.f3);
    self->f130 = func_0040CDD0(self, 1, info.fA, info.f7);
    return 1;
}
