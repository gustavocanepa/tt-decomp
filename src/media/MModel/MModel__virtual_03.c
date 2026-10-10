/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_001CDA70();                              /* extern */
void *func_001CDAA0(s32);                           /* extern */
s32 func_004755EC(f32, f32, f32);               /* extern */
s32 func_00475730(f32);                         /* extern */
s32 func_00475758(f32);                         /* extern */
s32 func_00475780(f32);                         /* extern */

struct MModel__virtual_03_temp_s1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct MModel__virtual_03_temp_s0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void MModel__virtual_03(s32 arg0) {
    struct MModel__virtual_03_temp_s0 *temp_s0;
    struct MModel__virtual_03_temp_s1 *temp_s1;

    temp_s1 = func_001CDA70();
    temp_s0 = func_001CDAA0(arg0);
    func_004755EC(temp_s1->unk0, temp_s1->unk4, temp_s1->unk8);
    func_00475780(temp_s0->unk8);
    func_00475730(temp_s0->unk0);
    func_00475758(temp_s0->unk4);
}
