typedef int s32;
typedef unsigned int u32;

extern "C" void func_002A7500(s32 arg0, u32 arg1);

extern "C" void func_002A7558(void) {
    func_002A7500(1, 0xFFFF);
}
