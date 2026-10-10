typedef int s32;

extern "C" void func_002A7578(s32 arg0, s32 *arg1);
extern "C" s32 func_0026E4F8(s32 arg0);

extern "C" void func_0026E5E8(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    s32 local = func_0026E4F8(0);

    func_002A7578(s0, &local);
}
