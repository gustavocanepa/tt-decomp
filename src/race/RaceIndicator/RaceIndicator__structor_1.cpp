typedef int s32;

extern void *D_005D0FB8;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void *func_0035E778(void *);
extern "C" void *Oscillator__setCycle(void *, float, float);
extern "C" void *func_0035E878(void *, float, float);
extern "C" void *Oscillator__setCount(void *, s32, s32);

struct RaceIndicator__structor_1_arg0 {
    char pad0[0x14];
    void *unk14;
    char pad18[0x20];
    void *unk38;
    void *unk3C;
    char unk40;
};

extern "C" void RaceIndicator__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    ((struct RaceIndicator__structor_1_arg0 *)arg0)->unk14 = &D_005D0FB8;
    func_0035E778((char *)arg0 + 0x18);
    ((struct RaceIndicator__structor_1_arg0 *)arg0)->unk38 = (void *)(-0x7f000001);
    ((struct RaceIndicator__structor_1_arg0 *)arg0)->unk3C = 0x0;
    ((struct RaceIndicator__structor_1_arg0 *)arg0)->unk40 = 0x0;
    Oscillator__setCycle((char *)arg0 + 0x18, 0.199999991804f, 0.500000014901f);
    func_0035E878((char *)arg0 + 0x18, 0.0f, 0.0699999947101f);
    Oscillator__setCount((char *)arg0 + 0x18, -0x1, 0x0); return;
}
