typedef int s32;
typedef long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

struct Global;
extern Global D_00585A30;

struct Info {
    char pad0[0x1A];
    u16 f1A;
    char pad1C[0x64];
};

struct Obj {
    char pad0[0x38];
    s64 id;
};

extern char D_005865D0[];

extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" f32 func_004394E8(void *table, f32 x);

extern "C" s32 func_0040DA90(Obj *self) {
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_00585A30, self->id, &info);
    return (s32)func_004394E8(D_005865D0, info.f1A);
}
