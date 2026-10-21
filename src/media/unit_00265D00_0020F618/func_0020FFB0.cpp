typedef int s32;

extern "C" void func_001C2E70(s32 *arg0);
extern "C" void func_001C2A20(s32 *arg0, s32 arg1);

extern "C" s32 func_0020FFB0(void) {
    s32 local;
    s32 result;

    func_001C2E70(&local);
    result = local;
    func_001C2A20(&local, 2);
    return result;
}
