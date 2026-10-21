typedef int s32;
extern "C" void *RaceInformation__structor_0(s32 *arg0);
extern "C" s32 func_0040BBD0(s32 arg0);
extern "C" char D_005CF580[];

extern "C" void func_00348C20(void *arg0) {
    RaceInformation__structor_0((s32 *)arg0);
    *(s32 *)((char *)arg0 + 0x134) = (s32)D_005CF580;

    char *p = (char *)arg0 + 0x188;
    for (s32 i = 5; i != -1; i--) {
        func_0040BBD0((s32)p);
        p += 0x1A0;
    }

    *(s32 *)((char *)arg0 + 0x120) = 6;

    char *q = (char *)arg0 + 0x310;
    for (s32 j = 0; j < 6; j++) {
        *(s32 *)(q + 0x8) = 0;
        *(s32 *)(q + 0xC) = 0;
        q += 0x1A0;
    }

    *(s32 *)((char *)arg0 + 0x178) = 0;
    *(s32 *)((char *)arg0 + 0x17C) = 0;
    *(s32 *)((char *)arg0 + 0x180) = 0;
}
