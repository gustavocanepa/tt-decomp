#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct RaceBase__virtual_92_arg0_unk6C {
    char pad0[0x70];
    void *unk70;
};
struct RaceBase__virtual_92_arg0 {
    char pad0[0x6C];
    struct RaceBase__virtual_92_arg0_unk6C *unk6C;
};

u8 RaceBase__getNumberOfLaps(struct RaceBase__virtual_92_arg0 *arg0) {
    return M2C_FIELD(arg0->unk6C->unk70, u8 *, 0x43);
}
