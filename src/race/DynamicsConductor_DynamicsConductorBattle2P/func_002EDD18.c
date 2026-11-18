#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_002E45F8(M2C_UNK *);                   /* extern */
M2C_UNK func_002ED0B0(s32, void *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_002EDC38(void *, M2C_UNK *, s32);      /* extern */
M2C_UNK func_002F35C0(M2C_UNK *, s32, M2C_UNK, M2C_UNK); /* extern */

void func_002EDD18(s32 arg0, s32 arg1) {
    struct StackFrame_002EDD18 { s8 pad0[0xE0]; s32 spE0; s8 pad1[0xFC]; s32 sp1E0; s8 pad2[0x1C]; } sp_;

    func_002E45F8(&sp_.sp1E0);
    func_002F35C0(&sp_.spE0, arg0, 0, 0);
    func_002ED0B0(arg0, ((s8 *)&sp_), &sp_.spE0, 0);
    func_002EDC38(((s8 *)&sp_), &sp_.spE0, arg1);
}
