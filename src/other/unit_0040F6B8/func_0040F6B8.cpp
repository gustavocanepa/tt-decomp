typedef int s32;
typedef long long s64;
typedef unsigned long long u64;

extern s32 D_00585CA4;
extern "C" s32 func_00411258(s32, s32, s32);

extern "C" s32 func_0040F6B8(u64 id, s32 x) {
    return func_00411258(D_00585CA4, (s32)(id & 0xFFFFFFFF), x) != 0;
}
