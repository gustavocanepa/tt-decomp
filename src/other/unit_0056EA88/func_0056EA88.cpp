typedef int s32;

extern "C" void func_0047F1D8(s32 arg0, s32 *arg1);

extern "C" void func_0056EA88(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp[2];
    sp[0] = arg1;
    sp[1] = arg2;
    func_0047F1D8(arg0, sp);
}
