extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_004730A8(...) throw();

struct func_003F3E68_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

void func_003F3E68(char *arg0) {
    s32 temp_v0;

    if (((struct func_003F3E68_arg0 *)arg0)->unk8 > 0) {
        do {
            func_004730A8();
            temp_v0 = ((struct func_003F3E68_arg0 *)arg0)->unk8 - 1;
            ((struct func_003F3E68_arg0 *)arg0)->unk8 = temp_v0;
        } while (temp_v0 > 0);
    }
    ((struct func_003F3E68_arg0 *)arg0)->unk0 = 1;
}

}
