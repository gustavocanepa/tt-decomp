#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00434C28(f32);                         /* extern */

struct func_00434C68_arg0_unk10 {
    char pad0[0x1024];
    f32 unk1024;
};
struct func_00434C68_arg0 {
    char pad0[0x10];
    struct func_00434C68_arg0_unk10 *unk10;
};

void func_00434C68(struct func_00434C68_arg0 *arg0) {
    func_00434C28(arg0->unk10->unk1024);
}
