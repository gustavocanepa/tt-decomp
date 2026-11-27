#include "types.h"
typedef s32 (*FnPtr)(void);

extern FnPtr D_005A4798;

extern "C" void func_00509240(void)
{
    D_005A4798();
}
