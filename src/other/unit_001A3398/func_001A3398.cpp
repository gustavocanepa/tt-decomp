typedef int s32;

extern "C" void func_00521558(s32 a0, s32 a1, s32 a2, const char *fmt, void *args);
extern "C" void func_00521598(s32 a0, s32 a1, s32 a2, const char *fmt, void *args);
extern "C" char D_001A3328[];

extern "C" void func_001A3398(s32 a0, s32 a1, s32 a2, s32 arg3, s32 t0) {
    s32 buf[2];
    if (t0 == 0) {
        func_00521558(a0, a1, a2, D_001A3328, buf);
    } else {
        buf[0] = arg3;
        buf[1] = t0;
        func_00521598(a0, a1, a2, D_001A3328, buf);
    }
}
