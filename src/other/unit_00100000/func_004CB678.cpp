typedef int s32;
typedef unsigned int u32;

extern "C" void func_004CB620(s32 arg0, u32 arg1);

extern "C" void func_004CB678(void) {
    func_004CB620(1, 0xFFFF);
}
