typedef int s32;

extern "C" void func_004A6500(s32 arg0, const char *arg1, s32 arg2);

extern "C" void func_003C7FD0(s32 arg0, s32 arg1) {
    func_004A6500(arg0, "%d", arg1);
}
