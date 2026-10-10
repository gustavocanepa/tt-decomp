typedef int s32;
typedef unsigned int u32;

extern "C" void func_002CA510(s32 arg0, u32 arg1);

extern "C" void func_002CA550(void) {
    func_002CA510(1, 0xFFFF);
}
