#include "types.h"

extern "C" s32 func_00396350(void);
extern "C" void func_00395638(char *a, s32 b, char *c, f32 t, s32 d);

extern "C" void func_00399200(char *arg0, s32 arg1, f32 t) {
    func_00395638(arg0 + 4, func_00396350(), arg0, t, arg1);
}
