#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct hInt__virtual_11_arg0 {
    char pad0[0x10];
    s32 unk10;
};

f32 hInt__toFloat(struct hInt__virtual_11_arg0 *arg0) {
    return (f32) arg0->unk10;
}
