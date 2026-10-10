/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;

extern s32 func_004E6338(void *fp, s32 c);

s32 func_004E8140(s32 c, void *fp) {
    if (c == -1) {
        return -1;
    }
    return func_004E6338(fp, (u8)c);
}
