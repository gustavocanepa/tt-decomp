typedef int s32;

extern void *D_005D0E88;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void *func_0035E778(void *);
extern "C" void *func_0035E868(void *, float, float);
extern "C" void *func_0035E878(void *, float, float);

extern "C" void RaceShiftTimingLampDisplay__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    *(void **)((char *)arg0 + 0x14) = &D_005D0E88;
    func_0035E778((char *)arg0 + 0x1c);
    func_0035E868((char *)arg0 + 0x1c, 0.149999994785f, 0.199999991804f);
    func_0035E878((char *)arg0 + 0x1c, 0.0200000000186f, 0.149999994785f); return;
}
