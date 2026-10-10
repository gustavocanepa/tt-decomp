#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004AC8F0_arg1 {
    char pad0[0x4];
    void *unk4;
};
struct func_004AC8F0_temp_v0 {
    char pad0[0x4];
    void *unk4;
};
struct func_004AC8F0_arg2 {
    char pad0[0x8];
    void *unk8;
};
struct func_004AC8F0_temp_a2 {
    char pad0[0x8];
    void *unk8;
};
struct func_004AC8F0_arg0 {
    void *unk0;
    void *unk4;
};
struct func_004AC8F0_var_a1 {
    char pad0[0x8];
    void *unk8;
};
struct func_004AC8F0_var_v1 {
    char pad0[0x4];
    void *unk4;
};

void func_004AC8F0(struct func_004AC8F0_arg0 *arg0, struct func_004AC8F0_arg1 *arg1, struct func_004AC8F0_arg2 *arg2) {
    struct func_004AC8F0_temp_a2 *temp_a2;
    struct func_004AC8F0_temp_v0 *temp_v0;
    struct func_004AC8F0_var_a1 *var_a1;
    struct func_004AC8F0_var_v1 *var_v1;

    temp_v0 = arg1->unk4;
    var_a1 = NULL;
    if (temp_v0 != NULL) {
        var_a1 = temp_v0->unk4;
    }
    temp_a2 = arg2->unk8;
    var_v1 = NULL;
    if (temp_a2 != NULL) {
        var_v1 = temp_a2->unk8;
    }
    if (temp_v0 == NULL) {
        arg0->unk0 = var_v1;
    } else if (var_a1 != NULL) {
        var_a1->unk8 = var_v1;
    }
    if (temp_a2 == NULL) {
        arg0->unk4 = var_a1;
        return;
    }
    if (var_v1 != NULL) {
        var_v1->unk4 = var_a1;
    }
}
