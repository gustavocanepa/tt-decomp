#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00586EE8[];
extern char D_00586EEC[];
extern char D_00586EF0[];
void func_0045E168(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    *(s32 *)D_00586EE8 = 1;
    *(s32 *)D_00586EF0 = *(s32 *)D_00586EEC;
}
