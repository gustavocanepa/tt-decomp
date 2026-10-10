#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00460960(void *);
struct func_0045F6D0_arg0 {
    char pad0[0x98];
    s32 unk98;
};

void func_0045F6D0(struct func_0045F6D0_arg0 *arg0) {
    if (arg0->unk98 == 0) {
        func_00460960(arg0);
        arg0->unk98 = 1;
    }
}
