#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct RaceSimpleBarMeter__virtual_03_arg0 {
    char pad0[0x18];
    f32 unk18;
    f32 unk1C;
};

void RaceSimpleBarMeter__update(struct RaceSimpleBarMeter__virtual_03_arg0 *arg0) {
    arg0->unk1C = (f32) arg0->unk18;
}
