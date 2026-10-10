typedef int s32;
typedef unsigned int u32;

extern "C" void func_001B3350(s32 arg0, u32 arg1);

extern "C" void func_001B33A8(void) {
    func_001B3350(1, 0xFFFF);
}
