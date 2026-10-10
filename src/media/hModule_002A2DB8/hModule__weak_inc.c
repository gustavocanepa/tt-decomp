#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct hClass__virtual_05_arg0 {
    char pad0[0x28];
    s32 unk28;
};

void hModule__weak_inc(struct hClass__virtual_05_arg0 *arg0) {
    arg0->unk28 = (s32) (arg0->unk28 + 1);
}
