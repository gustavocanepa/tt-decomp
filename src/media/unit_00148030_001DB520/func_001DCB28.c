#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001DC9F0(void *, s32, void *);         /* extern */

struct func_001DCB28_arg0 {
    char pad0[0x8];
    void *unk8;
};
struct func_001DCB28_var_s0 {
    char pad0[0x44];
    void *unk44;
};

void func_001DCB28(struct func_001DCB28_arg0 *arg0, s32 arg1) {
    void *var_a2;
    struct func_001DCB28_var_s0 *var_s0;

    var_s0 = arg0->unk8;
    if (var_s0 != NULL) {
        var_a2 = var_s0;
        do {
            var_s0 = var_s0->unk44;
            func_001DC9F0(arg0, arg1, var_a2);
            var_a2 = var_s0;
        } while (var_s0 != NULL);
    }
}
