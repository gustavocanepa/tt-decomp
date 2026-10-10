#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D5D18[];
struct ParticleManager__structor_1_arg0 {
    void *unk0;
    char pad4[0x3A8];
    s32 unk3AC;
};

void ParticleManager__structor_1(struct ParticleManager__structor_1_arg0 *arg0, s32 arg1) {
    arg0->unk3AC = (s32)D_005D5D18;
    func_0050E1A8(arg0->unk0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
