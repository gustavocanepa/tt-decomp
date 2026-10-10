typedef int s32;

extern void *D_005D0FB8;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void *func_0035E778(void *);
extern "C" void *func_0035E868(void *, float, float);
extern "C" void *func_0035E878(void *, float, float);
extern "C" void *func_0035E8F0(void *, s32, s32);

extern "C" void RaceIndicator__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    *(void **)((char *)arg0 + 0x14) = &D_005D0FB8;
    func_0035E778((char *)arg0 + 0x18);
    *(void **)((char *)arg0 + 0x38) = (void *)(-0x7f000001);
    *(void **)((char *)arg0 + 0x3c) = 0x0;
    *(char *)((char *)arg0 + 0x40) = 0x0;
    func_0035E868((char *)arg0 + 0x18, 0.199999991804f, 0.500000014901f);
    func_0035E878((char *)arg0 + 0x18, 0.0f, 0.0699999947101f);
    func_0035E8F0((char *)arg0 + 0x18, -0x1, 0x0); return;
}
