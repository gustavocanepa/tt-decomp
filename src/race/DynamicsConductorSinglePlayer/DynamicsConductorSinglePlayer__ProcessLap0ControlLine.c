#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002E6C08(void *);                      /* extern */
void *func_002F04D8();                              /* extern */
s32 func_003052F0(s32, s32, s32, s32); /* extern */
s32 func_002E69F8(void *);                      /* extern */

struct DynamicsConductorSinglePlayer__virtual_19_arg0 {
    s32 unk0;
    char pad4[0x20A27];
    s8 unk20A2B;
};
struct DynamicsConductorSinglePlayer__virtual_19_temp_v0 {
    char pad0[0x58B];
    u8 unk58B;
};

void DynamicsConductorSinglePlayer__ProcessLap0ControlLine(struct DynamicsConductorSinglePlayer__virtual_19_arg0 *arg0, s32 arg1) {
    s32 temp_s1;
    struct DynamicsConductorSinglePlayer__virtual_19_temp_v0 *temp_v0;

    temp_s1 = arg0->unk0;
    temp_v0 = func_002F04D8();
    if (temp_v0->unk58B == 1) {
        func_002E6C08(temp_v0);
        func_002E69F8(temp_v0);
        if (arg1 == 0) {
            func_003052F0(temp_s1, 4, 0, 0);
        }
    }
    arg0->unk20A2B = 0;
}
