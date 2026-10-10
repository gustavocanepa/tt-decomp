#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00426958_arg0 {
    char pad0[0x3F4];
    s32 unk3F4;
    s32 unk3F8;
    s32 unk3FC;
    char pad400[0x4];
    s32 unk404;
    f32 unk408;
};

void Pitmen__StatusTeam__clear(struct func_00426958_arg0 *arg0) {
    arg0->unk3F8 = 0;
    arg0->unk408 = 0x1.0000000000000p+1f;
    arg0->unk3FC = 0;
    arg0->unk404 = 0;
    arg0->unk3F4 = 0;
}
