typedef int s32;
typedef float f32;

extern char D_005F4468[];

extern "C" void func_0035A1D0(char *, f32);
extern "C" void RaceMessageDisplay__setFont(char *, char *, s32);
extern "C" void RaceMessageDisplay__setMessage(char *, char *, f32, f32);

extern "C" void func_003541F8(char *arg0, char *arg1, s32 arg2, s32 arg3, f32 fparg0) {
    char *temp_s0;
    f32 k;

    func_0035A1D0(arg0 + 0x2B7C, 0x1.333332p-3f);
    temp_s0 = arg0 + 0x2CCC;
    RaceMessageDisplay__setFont(temp_s0, D_005F4468, 0);
    k = 0x1p-2f;
    *(s32 *)(temp_s0 + 0x20) = arg2;
    *(f32 *)(temp_s0 + 0x18) = k;
    *(f32 *)(temp_s0 + 0x1C) = k;
    *(s32 *)(temp_s0 + 0x154) = arg3;
    RaceMessageDisplay__setMessage(temp_s0, arg1, fparg0, 0.0f);
}
