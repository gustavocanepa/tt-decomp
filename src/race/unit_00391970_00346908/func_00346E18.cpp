#include "types.h"

extern s32 D_00583FD8;

extern void RaceCarSound__setDiveNarrationFade(void);

void func_00346E18(s32 arg0)
{
    D_00583FD8 = arg0;
    RaceCarSound__setDiveNarrationFade();
}
