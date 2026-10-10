#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001D9E10();                            /* extern */

struct func_001D9E68_arg0 {
    char pad0[0x34];
    void *unk34;
};
struct func_001D9E68_arg1 {
    char pad0[0x34];
    void *unk34;
};
struct func_001D9E68_var_s2 {
    char pad0[0x8];
    void *unk8;
    char padC[0x8];
    void *unk14;
};
struct func_001D9E68_var_s3 {
    char pad0[0x8];
    void *unk8;
    char padC[0x8];
    void *unk14;
};
struct func_001D9E68_var_s0 {
    char pad0[0x44];
    void *unk44;
};
struct func_001D9E68_var_s1 {
    char pad0[0x44];
    void *unk44;
};

void func_001D9E68(struct func_001D9E68_arg0 *arg0, struct func_001D9E68_arg1 *arg1) {
    struct func_001D9E68_var_s0 *var_s0;
    struct func_001D9E68_var_s1 *var_s1;
    struct func_001D9E68_var_s2 *var_s2;
    struct func_001D9E68_var_s3 *var_s3;

    func_001D9E10();
    var_s2 = arg0->unk34;
    var_s3 = arg1->unk34;
    if (var_s2 != NULL) {
        do {
            var_s0 = var_s2->unk8;
            var_s1 = var_s3->unk8;
            if (var_s0 != NULL) {
                do {
                    func_001D9E68(var_s0, var_s1);
                    var_s0 = var_s0->unk44;
                    var_s1 = var_s1->unk44;
                } while (var_s0 != NULL);
            }
            var_s2 = var_s2->unk14;
            var_s3 = var_s3->unk14;
        } while (var_s2 != NULL);
    }
}
