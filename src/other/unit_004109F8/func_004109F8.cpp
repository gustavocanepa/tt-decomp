typedef int s32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;

struct Global;
extern Global D_00585A30;

struct Ref {
    s64 id;
    char pad8[0x18];
};

extern "C" s32 func_0040B910(Global *g, s64 id, void *info);

extern "C" s32 func_004109F8(s64 id, void *out) {
    if ((id >> 32) == 0x26) {
        Ref r;
        if (func_0040B910(&D_00585A30, id, &r) == 0) {
            return 0;
        }
        id = r.id;
    }
    return func_0040B910(&D_00585A30, id, out) != 0;
}
