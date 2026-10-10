typedef int s32;

extern void *D_005D1018;
extern "C" void RaceDisplayObjectBase__structor_0(void *);

struct RaceCapacityMonitor__structor_0_arg0 {
    char pad0[0x14];
    void *unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
};

extern "C" void RaceCapacityMonitor__structor_0(struct RaceCapacityMonitor__structor_0_arg0 *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    void *p0 = arg0->unk24;
    arg0->unk14 = &D_005D1018;
    arg0->unk24 = (void *)(((s32)p0 & (s32)-0x100));
    arg0->unk1C = 0x0;
    arg0->unk20 = 0x0;
    arg0->unk18 = 0x0;
}
