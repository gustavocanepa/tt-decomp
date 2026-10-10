typedef int s32;
typedef unsigned int u32;

extern "C" void func_001F0B00(s32 arg0, u32 arg1);

extern "C" void func_001F0B58(void) {
    func_001F0B00(1, 0xFFFF);
}
