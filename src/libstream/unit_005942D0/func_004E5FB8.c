#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004E5FB8_arg0_unk50 {
    char pad0[0x3C];
    s32 (*unk3C)();
};
struct func_004E5FB8_arg0 {
    char pad0[0x50];
    struct func_004E5FB8_arg0_unk50 *unk50;
};

void func_004E5FB8(struct func_004E5FB8_arg0 *arg0) {
    arg0->unk50->unk3C();
}
