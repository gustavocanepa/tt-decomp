typedef int s32;
typedef unsigned int u32;

extern "C" void func_004B6690(s32 arg0, u32 arg1);

extern "C" void func_004B6720(void) {
    func_004B6690(1, 0xFFFF);
}
