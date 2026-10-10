typedef int s32;

extern void *D_005D0E88;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void *func_0035E778(void *);
extern "C" void *Oscillator__setCycle(void *, float, float);
extern "C" void *func_0035E878(void *, float, float);

struct RaceShiftTimingLampDisplay__structor_1_arg0 {
    char pad0[0x14];
    void *unk14;
};

extern "C" void RaceShiftTimingLampDisplay__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    ((struct RaceShiftTimingLampDisplay__structor_1_arg0 *)arg0)->unk14 = &D_005D0E88;
    func_0035E778((char *)arg0 + 0x1c);
    Oscillator__setCycle((char *)arg0 + 0x1c, 0.149999994785f, 0.199999991804f);
    func_0035E878((char *)arg0 + 0x1c, 0.0200000000186f, 0.149999994785f); return;
}
