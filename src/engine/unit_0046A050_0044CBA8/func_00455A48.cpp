typedef int s32;
typedef unsigned int u32;

extern "C" u32 func_004558C0(s32);

extern "C" s32 func_00455A48(u32 *out, s32 key) {
    u32 v = func_004558C0(key);
    if (v < 12) {
        *out = v;
        return 1;
    }
    return 0;
}
