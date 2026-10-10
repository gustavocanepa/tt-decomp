#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00104838(void *);                      /* extern */

struct func_001056F0_temp_s1 {
    char pad0[0x78];
    s32 unk78;
};
struct func_001056F0_temp_s2 {
    char pad0[0x78];
    s32 unk78;
};

struct func_001056F0_arg0 {
    char pad0[0x18];
    f32 unk18;
    f32 unk1C;
};

void func_001056F0(void *arg0) {
    struct func_001056F0_temp_s1 *temp_s1;
    struct func_001056F0_temp_s2 *temp_s2;

    temp_s1 = arg0 + 0x44;
    func_00104838(temp_s1);
    temp_s2 = arg0 + 0xC0;
    func_00104838(arg0 + 0x80);
    temp_s1->unk78 = 0;
    func_00104838(temp_s2);
    func_00104838(arg0 + 0xFC);
    temp_s2->unk78 = 0;
    func_00104838(arg0 + 0x13C);
    ((struct func_001056F0_arg0 *)arg0)->unk18 = 0x1.1916860000000p+0f;
    ((struct func_001056F0_arg0 *)arg0)->unk1C = 0x1.d3f7ce0000000p-1f;
}
