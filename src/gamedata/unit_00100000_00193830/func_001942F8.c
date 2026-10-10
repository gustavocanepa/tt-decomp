#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00194C88(void *);                      /* extern */
s32 func_00197C90(void *);                      /* extern */
s32 func_00202968();                            /* extern */

extern char D_005AB008[];
extern char D_005AB388[];
struct func_001942F8_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
    char pad30[0x8C];
    s32 unkBC;
};

void func_001942F8(void *arg0) {
    func_00202968();
    ((struct func_001942F8_arg0 *)arg0)->unk4 = (s32)D_005AB008;
    ((struct func_001942F8_arg0 *)arg0)->unk2C = (s32)D_005AB388;
    func_00194C88(arg0 + 0xB4);
    func_00197C90(arg0 + 0xB8);
    ((struct func_001942F8_arg0 *)arg0)->unkBC = 0;
}
