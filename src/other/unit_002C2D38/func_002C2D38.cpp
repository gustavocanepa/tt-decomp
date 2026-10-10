extern "C" void func_004A45D0(int arg);
extern "C" void func_0050E1A8(void *arg);

extern "C" void func_002C2D38(void *arg0, int arg1) {
    func_004A45D0(*(int*)arg0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
