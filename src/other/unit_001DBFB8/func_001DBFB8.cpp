typedef int s32;
typedef unsigned int u32;

extern "C" void func_001DBE58(s32 arg0, u32 arg1);

extern "C" void func_001DBFB8(void) {
    func_001DBE58(1, 0xFFFF);
}
