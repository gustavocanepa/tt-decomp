typedef int s32;

extern "C" void func_001ADF50(void *arg0);
extern "C" void func_00473AD0(void *arg0, void *arg1);

extern "C" void func_001ADFC8(void *arg0) {
    char buf[0x10];
    func_001ADF50(buf);
    func_00473AD0(arg0, buf);
}
