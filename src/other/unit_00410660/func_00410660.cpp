typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Global;
extern Global D_00585A30;

struct Info {
    char pad0[0x3C];
    u8 f3C;
    char pad3D[0x63];
};

extern "C" s32 func_0040B980(Global *g, s64 id);
extern "C" s32 func_0040B910(Global *g, s64 id, Info *info);

extern "C" s32 func_00410660(s64 id) {
    if (func_0040B980(&D_00585A30, id) == 0) {
        return 0;
    }
    Info info;
    func_0040B910(&D_00585A30, id, &info);
    return info.f3C != 0;
}
