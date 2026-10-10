#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001DB058_arg1 {
    char pad0[0x14];
    void *unk14;
};
struct func_001DB058_arg0 {
    char pad0[0x34];
    void *unk34;
};
struct func_001DB058_temp_v0 {
    char pad0[0x10];
    void *unk10;
};

void func_001DB058(struct func_001DB058_arg0 *arg0, struct func_001DB058_arg1 *arg1) {
    struct func_001DB058_temp_v0 *temp_v0;

    arg1->unk14 = (void *) arg0->unk34;
    temp_v0 = arg0->unk34;
    if (temp_v0 != NULL) {
        temp_v0->unk10 = arg1;
    }
    arg0->unk34 = arg1;
}
