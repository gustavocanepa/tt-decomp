typedef int s32;
typedef short s16;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

/* the record SPEC_DATABASE__DatabaseStorage__getRow fills for an id */
struct Info {
    char pad0[0x18 + 58];
    u16 f18;
    char pad1A[0x66 - 58];
};

struct Global;

struct Obj {
    char pad0[0x38 - 8];
    s64 id;
};

extern Global D_00585A30;

extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);

extern "C" s32 func_0040D938(Obj *self) {
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_00585A30, self->id, &info);
    return info.f18;
}
