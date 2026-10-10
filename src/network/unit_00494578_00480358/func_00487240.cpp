extern "C" void func_004A45D0(int arg0);
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_00487240(int *arg0, int arg1) {
    int temp_v0 = *arg0;
    if (temp_v0 != 0) {
        func_004A45D0(temp_v0);
    }
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
