#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00586EE8[];
extern char D_00586EEC[];
extern char D_00586EF0[];
void func_0045E128(s32 arg0) {
    *(s32 *)D_00586EEC = arg0;
    if (*(s32 *)D_00586EE8 != 0) {
        *(s32 *)D_00586EF0 = arg0;
    }
}
