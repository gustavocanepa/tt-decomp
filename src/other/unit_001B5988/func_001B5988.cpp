typedef int s32;
typedef unsigned int u32;

extern "C" void func_001B56A0(s32 arg0, u32 arg1);

extern "C" void func_001B5988(void) {
    func_001B56A0(1, 0xFFFF);
}
