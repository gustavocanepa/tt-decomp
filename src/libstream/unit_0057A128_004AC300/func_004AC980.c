#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004AC980_arg0 {
    char pad0[0x4];
    void *unk4;
};

void *func_004AC980(struct func_004AC980_arg0 *arg0) {
    void *temp_s0;

    temp_s0 = arg0->unk4;
    if (temp_s0 != NULL) {
        func_004AC8B8(arg0, temp_s0);
    }
    return temp_s0;
}
