#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct SparkParticle__virtual_03_arg0 {
    char pad0[0x8];
    u16 unk8;
};

void SparkParticle__Init(struct SparkParticle__virtual_03_arg0 *arg0) {
    arg0->unk8 = (u16) (arg0->unk8 & 0xFFFE);
}
