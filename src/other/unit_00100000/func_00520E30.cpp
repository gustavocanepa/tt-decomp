extern "C" void func_004A45D0(int arg0);
extern "C" void func_0019B480(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005ACD40;
extern void *D_005AD0C8;

extern "C" void func_00520E30(void *arg0, int arg1) {
    int temp_v1;

    *(void **)((char *)arg0 + 0x4C) = &D_005ACD40;
    temp_v1 = *(int *)((char *)arg0 + 0x54);
    if (temp_v1 != 0) {
        func_004A45D0(temp_v1);
    }
    *(void **)((char *)arg0 + 0x4C) = &D_005AD0C8;
    func_0019B480(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
