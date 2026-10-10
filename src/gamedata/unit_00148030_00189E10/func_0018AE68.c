#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001ABC68(void *);                      /* extern */
s32 func_001C14A8(void *);                      /* extern */
s32 func_001C1578(void *);                      /* extern */
s32 func_00202968();                            /* extern */
s32 func_004AE9C0(void *);                      /* extern */

extern char D_005AA610[];
extern char D_005AA988[];
struct func_0018AE68_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
};

void func_0018AE68(void *arg0) {
    func_00202968();
    ((struct func_0018AE68_arg0 *)arg0)->unk4 = (s32)D_005AA610;
    ((struct func_0018AE68_arg0 *)arg0)->unk2C = (s32)D_005AA988;
    func_001C1578(arg0 + 0xB4);
    func_001C14A8(arg0 + 0x260);
    func_004AE9C0(arg0 + 0x264);
    func_001ABC68(arg0 + 0x2A0);
}
