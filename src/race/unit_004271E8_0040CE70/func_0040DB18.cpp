typedef int s32;
typedef long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

struct Global;
extern Global D_00585A30;

struct Info {
    char pad0[0x1C];
    u16 f1C;
    char pad1E[0x62];
};

struct Obj {
    char pad0[0x38];
    s64 id;
};

extern char D_005865D0[];

extern "C" void func_0040B910(Global *g, s64 id, Info *info);
extern "C" f32 func_00439550(void *table, f32 x);

extern "C" s32 func_0040DB18(Obj *self) {
    Info info;
    func_0040B910(&D_00585A30, self->id, &info);
    return (s32)func_00439550(D_005865D0, info.f1C);
}
