/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
struct Self {
    u32 unk0;
    char pad4[0x10];
    char *unk14;
    s32 unk18;
    s32 unk1C;
    u32 unk20;
    char pad24[0xC];
    s32 unk30;
    char sub34[0x20];
    char sub54[1];
};
extern char D_005D1290[];
extern "C" s32 RaceDisplayObjectBase__structor_0(void *);
extern "C" void func_0035E778(void *);
extern "C" s32 func_0035E910(void *);
extern "C" void RaceMessageDisplay__clear(void *);
extern "C" void RaceMessageDisplay__setFont(void *, const char *, s32);
extern "C" void Oscillator__setCycle(void *, float, float);
extern "C" void Oscillator__setCount(void *, s32, u8);
extern "C" void func_0035E878(void *, float, float);
extern "C" s32 AutomaticFader__reset(void *);

extern "C" s32 RaceMessageDisplay__structor_1(Self *arg0) {
    void *s1 = arg0->sub34;
    void *s2 = arg0->sub54;
    RaceDisplayObjectBase__structor_0(arg0);
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    arg0->unk14 = D_005D1290;
    arg0->unk30 = 0;
    func_0035E778(s1);
    func_0035E910(s2);
    arg0->unk0 = ~0xFFu & arg0->unk0;
    RaceMessageDisplay__clear(arg0);
    arg0->unk20 = 0x80C8C8C8;
    RaceMessageDisplay__setFont(arg0, "hn_20R", 0);
    Oscillator__setCycle(s1, 1.0f, 1.0f);
    Oscillator__setCount(s1, -1, 1);
    func_0035E878(s1, 0.0f, 0.0f);
    return AutomaticFader__reset(s2);
}
