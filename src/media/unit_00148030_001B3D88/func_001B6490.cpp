typedef int s32;
typedef unsigned int u32;

extern "C" void func_001B62E8(s32 arg0, u32 arg1);

extern "C" void func_001B6490(void) {
    func_001B62E8(1, 0xFFFF);
}
