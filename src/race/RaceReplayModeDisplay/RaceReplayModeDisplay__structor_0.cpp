extern "C" void *RaceMessageDisplay__structor_1(void *arg0);
extern "C" char D_005D0230[];

struct RaceReplayModeDisplay__structor_0_arg0 {
    char pad0[0x14];
    void *unk14;
    char pad18[0x138];
    int unk150;
    int unk154;
};

extern "C" void RaceReplayModeDisplay__structor_0(struct RaceReplayModeDisplay__structor_0_arg0 *arg0)
{
    RaceMessageDisplay__structor_1(arg0);
    arg0->unk154 = 0;
    arg0->unk150 = 0;
    arg0->unk14 = D_005D0230;
}
