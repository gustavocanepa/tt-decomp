/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_001B5610();                            /* extern */
void *GT4MC__FileGT4GameData__loadInstance(s32, M2C_UNK, M2C_UNK, void *, M2C_UNK, void *); /* extern */

extern char func_00541DC8[];
extern char func_0054D6E8[];
void func_0025D150(void *arg0, void *arg1) {
    void *temp_v0;
    void *var_v1;

    func_001B5610();
    var_v1 = NULL;
    if (arg1 != NULL) {
        temp_v0 = M2C_FIELD(arg1, void **, 4);
        var_v1 = GT4MC__FileGT4GameData__loadInstance(M2C_FIELD(temp_v0, s32 *, 4), (s32)func_00541DC8, 0, arg1 + M2C_FIELD(temp_v0, s16 *, 0), (s32)func_0054D6E8, arg1);
    }
    if (var_v1 != NULL) {
        M2C_FIELD(arg0, s32 *, 0xDC) = (s32) M2C_FIELD(var_v1, s32 *, 0xDC);
        M2C_FIELD(arg0, f32 *, 0xE0) = (f32) M2C_FIELD(var_v1, f32 *, 0xE0);
        M2C_FIELD(arg0, f32 *, 0xE4) = (f32) M2C_FIELD(var_v1, f32 *, 0xE4);
    }
}
