#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_0051D200(void *);
struct func_002C93D0_arg0 {
    char pad0[0x32798];
    void *unk32798;
};
struct func_002C93D0_temp_s0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
};

void func_002C93D0(struct func_002C93D0_arg0 *arg0) {
    struct func_002C93D0_temp_s0 *temp_s0;
    temp_s0 = arg0->unk32798;
    if (temp_s0 != NULL) {
        func_0051D200(temp_s0);
        temp_s0->unk10 = 0;
        temp_s0->unk14 = 0;
    }
}
