#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00357310(s32);                         /* extern */

extern char D_005F5948[];
extern char D_005F5958[];
extern char D_005F5968[];
extern char D_005F5980[];
struct func_00361F88_arg0 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
};

void RaceMTRGravityMeter__init_texset(struct func_00361F88_arg0 *arg0) {
    if (arg0->unk18 == 0) {
        arg0->unk18 = func_00357310((s32)D_005F5948);
        arg0->unk1C = func_00357310((s32)D_005F5958);
        arg0->unk20 = func_00357310((s32)D_005F5968);
        arg0->unk24 = func_00357310((s32)D_005F5980);
    }
}
