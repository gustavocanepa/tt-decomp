typedef int s32;
typedef unsigned int u32;

extern "C" void func_001C0CB0(s32 arg0, u32 arg1);

extern "C" void func_001C0D08(void) {
    func_001C0CB0(1, 0xFFFF);
}
