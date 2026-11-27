#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_002A2770(M2C_UNK *, M2C_UNK);          /* extern */
s32 func_002A2810(M2C_UNK *, void *);               /* extern */
M2C_UNK func_002A2CC0(M2C_UNK *);                   /* extern */
M2C_UNK func_002A4160(s32, M2C_UNK *, s32);         /* extern */
M2C_UNK func_002A6188(s32, void *, s32);            /* extern */
M2C_UNK func_002A75A8(void *, M2C_UNK);             /* extern */
M2C_UNK func_002A7A30(void *);                      /* extern */
s32 func_002BB3A8(s32);                             /* extern */

void func_002B4A60(s32 arg0, s32 arg1) {
    struct StackFrame_002B4A60 { s8 pad0[0x10]; s32 sp10; s8 pad1[0xC]; } sp_;

    func_002A7A30(((s8 *)&sp_));
    func_002A6188(func_002BB3A8(arg1), ((s8 *)&sp_), arg0 + 8);
    func_002A2CC0(&sp_.sp10);
    if (func_002A2810(&sp_.sp10, ((s8 *)&sp_)) != 0) {
        func_002A4160(func_002BB3A8(arg1), &sp_.sp10, arg0 + 0x18);
    }
    func_002A2770(&sp_.sp10, 2);
    func_002A75A8(((s8 *)&sp_), 2);
}
