#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_003696A0(s32, void *);                 /* extern */
M2C_UNK func_0037AFA8(void *);                      /* extern */
M2C_UNK func_0037AFD0(void *, M2C_UNK);             /* extern */
M2C_UNK RacePlayerSpec__createEquipments(void *, s64, M2C_UNK, M2C_UNK); /* extern */

void func_00339990(void *arg0, s32 arg1) {
    struct StackFrame_00387750 { s8 pad0[0x1A0]; } sp_;
    if (M2C_FIELD(arg0, s64 *, 0x2D0) != 0) {
        func_0037AFA8(((s8 *)&sp_));
        RacePlayerSpec__createEquipments(((s8 *)&sp_), M2C_FIELD(arg0, s64 *, 0x2D0), -1, 1);
        func_003696A0(arg1, ((s8 *)&sp_));
        func_0037AFD0(((s8 *)&sp_), 2);
    }
}
