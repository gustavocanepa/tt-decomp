typedef int s32;
typedef unsigned int u32;

extern "C" s32 func_0040EE28(void);
extern "C" u32 func_004A8268(const char *a, const char *b);
extern "C" char D_005FBF88[];

extern "C" s32 func_0040F430(void) {
    s32 r = func_0040EE28();
    if (r == 0) return 0;
    return func_004A8268(D_005FBF88, (char *)r + 2) < 1;
}
