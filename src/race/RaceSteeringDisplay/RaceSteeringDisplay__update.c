#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct RaceSteeringDisplay__virtual_03_arg0 {
    char pad0[0x1C];
    f32 unk1C;
    f32 unk20;
};

void RaceSteeringDisplay__update(struct RaceSteeringDisplay__virtual_03_arg0 *arg0) {
    arg0->unk20 = (f32) arg0->unk1C;
}
