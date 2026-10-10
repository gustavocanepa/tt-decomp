typedef int s32;
typedef long long s64;

struct Global;
extern Global D_00585A30;

extern "C" s64 func_0040B840(Global *g, const char *key, s32 kind);
extern "C" s32 func_0040EC90(void *out, s64 id);

extern "C" s32 func_0040ED30(void *out, const char *key) {
    s64 id = func_0040B840(&D_00585A30, key, 0x23);
    if (id == -1) {
        return 0;
    }
    return func_0040EC90(out, id);
}
