/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001013F0();                            /* extern */
s32 GranTurismo4__BGMPlayList__setDefault(s32, s32);                /* extern */

extern char D_005857DC[];
void func_001016A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_001013F0();
    GranTurismo4__BGMPlayList__setDefault(*(s32 *)(s32)D_005857DC + 0x710, 0);
    GranTurismo4__BGMPlayList__setDefault(*(s32 *)(s32)D_005857DC + 0xF20, 0);
}
