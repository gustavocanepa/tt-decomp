#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005DAEE0[];
struct GTSOUNDINSTRUMENT {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    void * unk1C;
};
struct EngineSound {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    void * unk1C;
    void * unk20;
};
s32 func_0050E1A8(struct EngineSound *);        /* extern */

void func_004B3008(struct EngineSound *arg0, s32 arg1) {
    arg0->unk1C = (void *)(s32)D_005DAEE0;
    func_004A69F8((struct GTSOUNDINSTRUMENT *) arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
