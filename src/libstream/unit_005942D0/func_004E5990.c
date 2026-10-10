#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004E5990_arg0_unk50 {
    char pad0[0x14];
    s32 (*unk14)();
};
struct func_004E5990_arg0 {
    char pad0[0x50];
    struct func_004E5990_arg0_unk50 *unk50;
};

void func_004E5990(struct func_004E5990_arg0 *arg0) {
    arg0->unk50->unk14();
}
