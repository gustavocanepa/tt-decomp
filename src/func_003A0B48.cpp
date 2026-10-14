typedef float f32;
typedef int s32;
typedef short s16;
extern char D_00584BD8[];
extern "C" void func_003A0B20(s32 a, s32 b, f32 c);

extern "C" void SetupBrakeHeatParameters(void) {
    s32 i;
    s32 j;
    char *base = D_00584BD8;
    s16 *p;
    s16 v;
    for (i = 0; i < 5; i++) {
        p = (s16 *)((unsigned)((((i << 1) + i) << 4)) + (unsigned)base);
        for (j = 0; j < 24; j++) {
            v = *p;
            p++;
            func_003A0B20(i, j, (f32)v * 0.01f);
        }
    }
}
