extern "C" void func_004E6668();
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_004E5578(void *arg0, int arg1) {
    func_004E6668();
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
