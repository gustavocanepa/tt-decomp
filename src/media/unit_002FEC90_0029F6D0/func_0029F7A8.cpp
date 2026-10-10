typedef int s32;
typedef unsigned char u8;

extern "C" u8 func_0029F6D0(void *arg0);

extern "C" s32 func_0029F7A8(s32 arg0, u8 *arg1) {
    s32 s1 = arg0;
    *arg1 = func_0029F6D0((void *)s1);
    return s1;
}
