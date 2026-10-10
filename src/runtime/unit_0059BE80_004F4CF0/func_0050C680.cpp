/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

extern "C" s32 func_004A8268(const char *a, const char *b);

extern "C" s32 func_0050C680(const char **a, const char **b) {
    s32 r = 0;
    if (b == a || func_004A8268(*a, *b) == 0) {
        r = 1;
    }
    return r;
}
