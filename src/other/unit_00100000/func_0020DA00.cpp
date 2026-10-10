extern "C" int func_00206DD8(int arg0);
extern "C" int func_0020D610(int arg0);
extern "C" void func_0020D9D8(void);

extern "C" void func_0020DA00(int arg0, int arg1) {
    int s0 = arg0;
    int s1 = arg1;
    func_0020D9D8();
    if (func_0020D610(s0) != 0) {
        if (func_00206DD8(s0) != 0) {
            func_0020DA00(func_00206DD8(s0), s1);
        }
    }
}
