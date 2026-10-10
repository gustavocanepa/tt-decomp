extern "C" void *RaceMessageDisplay__structor_1(void *arg0);
extern "C" char D_005D0230[];

extern "C" void RaceReplayModeDisplay__structor_0(void *arg0)
{
    RaceMessageDisplay__structor_1(arg0);
    *(int *)((char *)arg0 + 0x154) = 0;
    *(int *)((char *)arg0 + 0x150) = 0;
    *(void **)((char *)arg0 + 0x14) = D_005D0230;
}
