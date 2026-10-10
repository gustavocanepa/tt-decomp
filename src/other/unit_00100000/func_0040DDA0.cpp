typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Global;
extern Global D_00585A30;

struct Info {
    char pad0[0x11 + 2];
    u8 f11;
    char pad12[0xE - 2];
};

struct Obj {
    s64 id;
};

extern "C" s32 func_0040B910(Global *g, s64 id, Info *info);
extern "C" s32 func_0040E3C8(Obj *self);

extern "C" s32 func_0040DDA0(Obj *self) {
    s32 r = 0;
    Info info;
    if (func_0040B910(&D_00585A30, self->id, &info) == 0) {
        return 0;
    }
    {
        switch (info.f11) {
        case 0:
        case 3:
            if (func_0040E3C8(self) > 0) {
                r = 1;
            }
            break;
        case 1:
            r = 3;
            break;
        case 2:
            r = 2;
            break;
        }
    }
    return r;
}
