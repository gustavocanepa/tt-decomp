#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_002944D0(void *, s32, M2C_UNK *);      /* extern */
M2C_UNK func_002A75A8(void *, M2C_UNK);             /* extern */
M2C_UNK func_002ADBF0(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_002B01F8(M2C_UNK *);                   /* extern */

void func_00292BA0(void *arg0) {
    struct StackFrame_00292BA0 { s8 pad0[0x10]; s32 sp10; s8 pad1[0xC]; } sp_;
    s32 temp_s1;

    temp_s1 = M2C_FIELD(arg0, s32 *, 0x78);
    func_002B01F8(&sp_.sp10);
    func_002944D0(((s8 *)&sp_), temp_s1, &sp_.sp10);
    func_002A75A8(((s8 *)&sp_), 2);
    func_002ADBF0(&sp_.sp10, 2);
}
