typedef int s32;

extern void *D_005DB608;
extern "C" void func_004EC2C8(void *, void *, s32);
extern "C" void func_004E83D0(void *, s32);
extern "C" void func_0050E1A8(void *);

extern "C" void func_004ECE18(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x50) = &D_005DB608;
    func_004EC2C8(arg0, *(void **)((char *)arg0 + 0x10), ((s32)*(void **)((char *)arg0 + 0x14) - (s32)*(void **)((char *)arg0 + 0x10)));
    func_004E83D0(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_0050E1A8(arg0);
    }
}
