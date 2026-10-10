typedef int s32;

extern "C" void func_001E9718(s32 arg0, s32 arg1);
extern "C" s32 func_00210118(void);

extern "C" void func_001FA1A8(s32 arg0) {
    s32 v0 = func_00210118();
    if (v0 != 0) {
        func_001E9718(v0, arg0);
    }
}
