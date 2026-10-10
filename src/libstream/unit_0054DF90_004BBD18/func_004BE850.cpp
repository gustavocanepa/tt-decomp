typedef int s32;
typedef unsigned int u32;

extern "C" void func_004BE650(s32 arg0, u32 arg1);

extern "C" void func_004BE850(void) {
    func_004BE650(1, 0xFFFF);
}
