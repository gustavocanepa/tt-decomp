/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
struct Self {
    char pad0[0x3C];
    float unk3C;
    char pad40[0x8];
    float unk48;
    float unk4C;
    u32 unk50;
};
extern "C" void RaceMTRMultiFunctionDisplay__showInformation(Self *self, u32 arg1, float f);

extern "C" void RaceMTRMultiFunctionDisplay__update_auto_info(Self *arg0, float fparg0) {
    s32 a = arg0->unk4C < 200.0f;
    s32 b = arg0->unk3C < 200.0f;
    if (a == b) {
        float t = arg0->unk48 + fparg0;
        arg0->unk48 = t;
        if ((u8)arg0->unk50 == 0 && t > 0.5f) {
            arg0->unk50 = (arg0->unk50 & ~0xFF) | 1;
            RaceMTRMultiFunctionDisplay__showInformation(arg0, b ? 2 : 3, 3.0f);
        }
    } else {
        arg0->unk48 = 0.0f;
        arg0->unk50 = arg0->unk50 & ~0xFF;
    }
    arg0->unk4C = arg0->unk3C;
}
