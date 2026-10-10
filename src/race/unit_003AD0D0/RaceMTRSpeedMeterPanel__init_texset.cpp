extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00357310(...) throw();

extern char D_005F59A0[];
extern char D_005F59B0[];
extern char D_005F59B8[];
extern char D_005865D0[];
struct func_00362638_arg0 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
};

void RaceMTRSpeedMeterPanel__init_texset(char *arg0) {
    s32 var_a0;
    s32 temp_v1;

    if (((struct func_00362638_arg0 *)arg0)->unk18 == 0) {
        temp_v1 = *(s32 *)D_005865D0;
        var_a0 = 0;
        switch (temp_v1) {                          /* irregular */
        case 0:
            var_a0 = (s32)D_005F59A0;
            break;
        case 1:
            var_a0 = (s32)D_005F59B0;
            break;
        }
        ((struct func_00362638_arg0 *)arg0)->unk18 = func_00357310(var_a0);
        ((struct func_00362638_arg0 *)arg0)->unk1C = func_00357310((s32)D_005F59B8);
    }
}

}
