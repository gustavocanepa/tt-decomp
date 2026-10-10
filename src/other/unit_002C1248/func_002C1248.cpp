extern "C" void func_002C1050(int arg0);
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_002C1248(int *arg0, int arg1) {
    int temp_v0 = *arg0;
    if (temp_v0 != 0) {
        func_002C1050(temp_v0);
    }
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
