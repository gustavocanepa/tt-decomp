#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004C5768_arg0 {
    s64 unk0;
    s64 unk8;
    s64 unk10;
    s64 unk18;
    s64 unk20;
};
struct func_004C5768_arg1 {
    s64 unk0;
    s64 unk8;
    s64 unk10;
    s64 unk18;
    s64 unk20;
};

void func_004C5768(struct func_004C5768_arg0 *arg0, struct func_004C5768_arg1 *arg1) {
    arg0->unk0 = (s64) arg1->unk0;
    arg0->unk8 = (s64) arg1->unk8;
    arg0->unk10 = (s64) arg1->unk10;
    arg0->unk18 = (s64) arg1->unk18;
    arg0->unk20 = (s64) arg1->unk20;
}
