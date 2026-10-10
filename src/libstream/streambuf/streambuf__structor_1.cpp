typedef int s32;

extern void *D_005DB528;
extern "C" void func_004E6298(void *, s32);
extern "C" void func_0050E1A8(void *);

extern "C" void streambuf__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x50) = &D_005DB528;
    func_004E6298(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_0050E1A8(arg0);
    }
}
