typedef int s32;

extern void *D_005D0290;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void *func_0035E910(void *);
extern "C" void *AutomaticFader__reset(void *);

struct RaceMusicDisplay__structor_1_arg0 {
    char pad0[0x14];
    void *unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
};

extern "C" void RaceMusicDisplay__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    ((struct RaceMusicDisplay__structor_1_arg0 *)arg0)->unk18 = 0x0;
    ((struct RaceMusicDisplay__structor_1_arg0 *)arg0)->unk1C = 0x0;
    ((struct RaceMusicDisplay__structor_1_arg0 *)arg0)->unk14 = &D_005D0290;
    ((struct RaceMusicDisplay__structor_1_arg0 *)arg0)->unk20 = 0x0;
    ((struct RaceMusicDisplay__structor_1_arg0 *)arg0)->unk24 = 0x0;
    func_0035E910((char *)arg0 + 0x28);
    AutomaticFader__reset((char *)arg0 + 0x28); return;
}
