typedef long long s64;
typedef unsigned long long u64;
typedef int s32;
typedef unsigned int u32;
struct Obj;
extern "C" s64 func_00412018(Obj *) throw();
extern "C" s64 func_00412028(Obj *, s32) throw();
extern "C" s32 func_00412060(Obj *o, u64 key) {
    s32 cnt = 0;
    s32 i = 0;
    s32 n = (s32)func_00412018(o);
    while (i < n) {
        s64 v = func_00412028(o, i);
        s64 hi = (s64)((u64)v & 0xFFFFFFFF00000000ULL) >> 32;
        if (key == hi) cnt++;
        i++;
        if (key < hi) break;
    }
    return cnt;
}
