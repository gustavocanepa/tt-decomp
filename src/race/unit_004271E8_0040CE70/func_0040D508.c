typedef int s32;
typedef signed char s8;
s32 func_0040D540(char *a, s32 b);
s32 func_0040D508(char *arg0) {
    s32 c = *(s8 *)(arg0 + 0x18);
    if (c == -1) return 0;
    return func_0040D540(arg0, c);
}
