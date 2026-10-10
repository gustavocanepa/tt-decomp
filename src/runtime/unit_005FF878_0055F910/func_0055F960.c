#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0055F960_arg0 {
    s128 unk0;
    s128 unk10;
};
struct func_0055F960_arg1 {
    s128 unk0;
    s128 unk10;
};

void *func_0055F960(struct func_0055F960_arg0 *arg0, struct func_0055F960_arg1 *arg1) {
    arg0->unk0 = (s128) arg1->unk0;
    arg0->unk10 = (s128) arg1->unk10;
    return arg0;
}
