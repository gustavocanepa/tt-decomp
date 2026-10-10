typedef int s32;

extern "C" void func_003F94B0(char *dst, const char *src, s32 n, s32 idx) {
    s32 i;
    s32 off = idx * n;
    for (i = 0; i < n; i++)
        dst[i] = src[off + i];
    dst[i] = 0;
}
