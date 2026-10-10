#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004BBF58(s32);                         /* extern */

struct func_001B1F30_arg0 {
    char pad0[0xE4];
    s32 unkE4;
    char padE8[0x24];
    s32 unk10C;
};

void func_001B1F30(struct func_001B1F30_arg0 *arg0) {
    func_004BBF58(arg0->unkE4);
    arg0->unk10C = 0;
}
