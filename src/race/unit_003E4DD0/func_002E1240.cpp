#include "types.h"

struct func_002E1240_arg0 {
    char pad0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    char pad1C[0x34 - 0x1C];
    s32 unk34;
    f32 unk38;
    s32 unk3C;
    s32 unk40;
    u8 unk44;
    u8 unk45;
    char pad46[6];
    s32 unk4C;
    s32 unk50;
    s32 unk54;
};

extern "C" u8 GT4Model__BinStreamReader__read8u(s32);
extern "C" f32 GT4Model__BinStreamReader__readFloat(s32);
extern "C" void func_002DE508(char *);

extern "C" void func_002E1240(struct func_002E1240_arg0 *arg0, s32 arg1) {
    char *p0;
    char *p1;
    s32 n;

    arg0->unk44 = GT4Model__BinStreamReader__read8u(arg1);
    arg0->unk4 = (f32)(s32)GT4Model__BinStreamReader__read8u(arg1) * 0x1.921FB4p1f * 0x1.0p-7f;
    arg0->unk8 = (f32)(s32)GT4Model__BinStreamReader__read8u(arg1) * 0x1.921FB4p1f * 0x1.0p-7f;
    arg0->unkC = (f32)(s32)GT4Model__BinStreamReader__read8u(arg1) * 0x1.921FB4p1f * 0x1.0p-7f;
    arg0->unk10 = GT4Model__BinStreamReader__readFloat(arg1);
    arg0->unk14 = GT4Model__BinStreamReader__readFloat(arg1);
    arg0->unk18 = GT4Model__BinStreamReader__readFloat(arg1);
    p1 = (char *)arg0 + 0x28;
    p0 = (char *)arg0 + 0x1C;
    n = 2;
    do {
        n = n - 1;
        *(s32 *)p0 = 0;
        *(s32 *)p1 = 0;
        p1 += 4;
        p0 += 4;
    } while (n >= 0);
    arg0->unk34 = 0;
    arg0->unk38 = 0x1.0p0f;
    arg0->unk3C = 0;
    arg0->unk40 = 0;
    arg0->unk45 = 0;
    arg0->unk4C = 0;
    arg0->unk50 = 0;
    arg0->unk54 = 0;
    func_002DE508((char *)arg0);
}
