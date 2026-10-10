typedef int s32;
typedef unsigned int u32;

extern "C" void func_001B1C40(s32 arg0, u32 arg1);

extern "C" void func_001B1C98(void) {
    func_001B1C40(1, 0xFFFF);
}
