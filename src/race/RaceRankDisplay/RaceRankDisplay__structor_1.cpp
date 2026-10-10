typedef int s32;

extern void *D_005D14A8;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void *func_0035E910(void *);
extern "C" void *func_0035EA08(void *, float);

extern "C" void RaceRankDisplay__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    *(void **)((char *)arg0 + 0x18) = 0x0;
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    *(void **)((char *)arg0 + 0x14) = &D_005D14A8;
    *(void **)((char *)arg0 + 0x20) = 0x0;
    func_0035E910((char *)arg0 + 0x24);
    func_0035EA08((char *)arg0 + 0x24, 0.0f); return;
}
