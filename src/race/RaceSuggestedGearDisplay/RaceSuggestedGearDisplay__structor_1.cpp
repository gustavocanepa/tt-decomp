typedef int s32;

extern void *D_005D0EF0;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void *func_0035E778(void *);
extern "C" void *func_0035E910(void *);
extern "C" void *func_0035E868(void *, float, float);
extern "C" void *func_0035E878(void *, float, float);

extern "C" void RaceSuggestedGearDisplay__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    *(void **)((char *)arg0 + 0x14) = &D_005D0EF0;
    func_0035E778((char *)arg0 + 0x18);
    func_0035E910((char *)arg0 + 0x38);
    *(char *)((char *)arg0 + 0x54) = 0x0;
    *(char *)((char *)arg0 + 0x55) = 0x0;
    *(void **)((char *)arg0 + 0x54) = (void *)(*(unsigned short *)((char *)arg0 + 0x54));
    func_0035E868((char *)arg0 + 0x18, 0.149999994785f, 0.329999990761f);
    func_0035E878((char *)arg0 + 0x18, 0.0200000000186f, 0.0599999995902f); return;
}
