typedef int s32;

extern "C" s32 func_003D8378(s32 arg0, s32 arg1);
extern "C" void func_003D9C20(s32 arg0, s32 arg1);

extern "C" s32 func_003D8340(s32 arg0, s32 arg1) {
    func_003D9C20(arg0, arg1);
    return func_003D8378(arg0, arg1);
}
