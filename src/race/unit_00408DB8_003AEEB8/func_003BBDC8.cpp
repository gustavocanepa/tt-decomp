typedef int s32;

extern "C" void func_003BBE08(s32 arg0);
extern "C" void func_003E3A60(s32 arg0, s32 arg2);

extern "C" void func_003BBDC8(s32 arg0, s32 arg1, s32 arg2) {
    func_003BBE08(arg0);
    func_003E3A60(arg2, arg0 + 0x590);
}
