#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_001036F0(void *, void *);
struct func_00104390_arg1 {
    char pad0[0xAC];
    s32 unkAC;
};
struct func_00104390_arg0 {
    char pad0[0x44];
    s32 unk44;
};

void func_00104390(struct func_00104390_arg0 *arg0, struct func_00104390_arg1 *arg1) {
    func_001036F0(arg0, arg1);
    if (arg1->unkAC == 0) {
        arg0->unk44 = 0;
    }
}
