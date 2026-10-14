typedef int s32;
typedef unsigned int u32;
typedef signed char s8;

extern "C" char *func_004F7B74(char *dst, const char *src);
extern "C" void func_004F7A30(char *dst, char *src);
extern "C" s32 func_0047DB20(s32 arg0, s32 arg1, s32 arg2);
extern "C" s32 func_0047DB58(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern "C" void *func_004F64C4(void *dst, const void *src, u32 n);

extern "C" s32 func_001980C8(s32 arg0, s8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    char loc[0xA0];
    char *sp = loc;
    func_004F7B74(sp, (char *)arg0 + 4);
    if (*arg1 != 0) {
        func_004F7A30(sp, (char *)arg1 + 1);
    }
    if (arg4 != 0) {
        func_0047DB20((s32)(loc + 0x80), (s32)sp, 1);
        func_004F64C4((void *)arg2, (const void *)*(s32 *)(loc + 0x90), (u32)arg3);
    } else {
        func_0047DB58((s32)(loc + 0x80), (s32)sp, arg2, arg3, 1);
    }
    return 0;
}
