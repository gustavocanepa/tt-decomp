typedef int s32;
typedef unsigned int u32;

extern "C" void func_001F4360(s32 arg0, u32 arg1);

extern "C" void func_001F4540(void) {
    func_001F4360(1, 0xFFFF);
}
