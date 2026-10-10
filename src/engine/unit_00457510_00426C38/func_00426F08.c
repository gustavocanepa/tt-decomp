#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00426F08_arg0 {
    char pad0[0x394];
    f32 unk394;
    f32 unk398;
};
struct func_00426F08_var_v0 {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
};

void func_00426F08(void *arg0, f32 fparg0, f32 fparg1) {
    s32 var_v1;
    void *var_v0;

    var_v0 = arg0 + 0xC;
    var_v1 = 7;
    ((struct func_00426F08_arg0 *)arg0)->unk394 = (f32) (((struct func_00426F08_arg0 *)arg0)->unk394 + fparg0);
    ((struct func_00426F08_arg0 *)arg0)->unk398 = (f32) (((struct func_00426F08_arg0 *)arg0)->unk398 + fparg1);
    do {
        var_v1 -= 1;
        ((struct func_00426F08_var_v0 *)var_v0)->unk10 = (f32) (((struct func_00426F08_var_v0 *)var_v0)->unk10 + fparg0);
        ((struct func_00426F08_var_v0 *)var_v0)->unk14 = (f32) (((struct func_00426F08_var_v0 *)var_v0)->unk14 + fparg1);
        var_v0 += 0x44;
    } while (var_v1 >= 0);
}
