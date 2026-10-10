extern "C" void PitmenTiny__clear();
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_003D0EE0(void *arg0, int arg1) {
    PitmenTiny__clear();
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
