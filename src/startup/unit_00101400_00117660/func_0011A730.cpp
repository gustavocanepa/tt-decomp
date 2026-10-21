typedef int s32;

extern "C" char D_0011C6B0[];
extern "C" char D_0011C6D8[];
extern "C" char D_00579808[];
extern "C" char D_00579828[];

extern "C" void func_0046F0F8(s32 arg0);
extern "C" void func_004702D8(s32 arg0, float arg1);
extern "C" s32 func_0011C768(s32 arg0, s32 arg1);
extern "C" s32 func_0011C780(s32 arg0, s32 arg1);
extern "C" void func_0011AA60(s32 arg0, s32 arg1, char *arg2, char *arg3, float arg4, float arg5);
extern "C" void func_00478C98(s32 arg0);

extern "C" void func_0011A730(s32 arg0, s32 arg1, float fparg0) {
    func_0046F0F8(6);
    func_004702D8(0x64, 0.5f);
    if (func_0011C768(arg0, arg1) != 0) {
        float v = 50.0f;
        if (arg1 != 0) {
            v = -50.0f;
        }
        func_0011AA60(arg0, arg1, D_0011C6B0, D_00579808 + arg1 * 16, fparg0, v);
    }
    if (func_0011C780(arg0, arg1) != 0) {
        float w = 50.0f;
        if (arg1 != 0) {
            w = -50.0f;
        }
        func_0011AA60(arg0, arg1, D_0011C6D8, D_00579828 + arg1 * 16, fparg0, w);
    }
    func_00478C98(6);
}
