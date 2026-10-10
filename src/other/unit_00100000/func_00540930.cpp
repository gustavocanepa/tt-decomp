extern "C" void func_00511F78(void *arg0, int arg1);
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_00540930(void *arg0, int arg1) {
    func_00511F78(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
