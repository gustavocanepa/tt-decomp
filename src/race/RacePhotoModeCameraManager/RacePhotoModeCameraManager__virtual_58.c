/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00318708(s32);                         /* extern */
s32 func_00318780(s32);                         /* extern */

void RacePhotoModeCameraManager__virtual_58(s32 arg0) {
    s32 temp_s0;

    temp_s0 = arg0 + 0xF00;
    func_00318708(temp_s0);
    func_00318780(temp_s0);
}
