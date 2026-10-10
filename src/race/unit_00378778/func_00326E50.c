#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005CA488[];
struct func_00326E50_arg0 {
    s32 unk0;
    char pad4[0x180];
    s32 unk184;
};

void *func_00326E50(struct func_00326E50_arg0 *arg0) {
    func_003216C0(arg0);
    arg0->unk184 = -1;
    arg0->unk0 = (s32)D_005CA488;
    return (void *)-1;
}
