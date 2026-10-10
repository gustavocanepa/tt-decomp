#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005B1438[];
struct MModel {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    f32 unk24;
    s32 unk28;
    s32 unk2C;
    char unk_30[0x18];
    void * unk48;
};
struct CompatibleModel {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    f32 unk24;
    s32 unk28;
    s32 unk2C;
    char unk_30[0x18];
    void * unk48;
    void * unk4C;
    s32 unk50;
    void * unk54;
    s32 unk58;
};
s32 func_0050E1A8(struct CompatibleModel *);    /* extern */

void CompatibleModel__structor_1(struct CompatibleModel *arg0, s32 arg1) {
    arg0->unk48 = (void *)(s32)D_005B1438;
    MModel__structor_1((struct MModel *) arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
