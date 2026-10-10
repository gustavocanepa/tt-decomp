typedef int s32;
typedef short s16;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

/* the record func_0040B910 fills for an id */
struct Info {
    char pad0[0x8];
    u16 f8;
    char padA[0x16];
};

struct Global;

struct Obj {
    char pad0[0x80];
    s64 id;
};

extern Global D_00585A30;

extern "C" void func_0040B910(Global *g, s64 id, Info *info);

extern "C" s32 func_0040DC40(Obj *self) {
    Info info;
    func_0040B910(&D_00585A30, self->id, &info);
    return info.f8;
}
