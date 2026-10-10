#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_00253E38();                                /* extern */
f32 func_00254328(s32);                             /* extern */

f32 mListBox__getVolumeRatio(s32 arg0) {
    f32 temp_f20;

    temp_f20 = func_00253E38();
    return temp_f20 / func_00254328(arg0);
}
