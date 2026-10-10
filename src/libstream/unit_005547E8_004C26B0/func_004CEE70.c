#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004CEA90(void *);
s32 func_004C1818(void *);                          /* extern */

struct func_004CEE70_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    char pad2C[0x30];
    s32 unk5C;
    s32 unk60;
};

void func_004CEE70(struct func_004CEE70_arg0 *arg0) {
    func_004F6678(arg0, 0, 8);
    arg0->unk1C = 0;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
    arg0->unk5C = func_004C1818(arg0);
    arg0->unk60 = func_004CEA90(arg0);
}
