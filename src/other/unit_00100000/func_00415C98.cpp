typedef int s32;

extern "C" void func_00415CC0(s32 arg0, char *arg1);

extern "C" void func_00415C98(s32 arg0, char arg1) {
    char buf[2];
    buf[0] = arg1;
    buf[1] = 0;
    func_00415CC0(arg0, buf);
}
