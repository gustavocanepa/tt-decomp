typedef int s32;
typedef unsigned short u16;

extern "C" void func_0029F9D0(s32 arg0, u16 arg1);

extern "C" s32 func_0029FAB0(s32 arg0, s32 arg1) {
    func_0029F9D0(arg0, arg1 & 0xFFFF);
    return arg0;
}
