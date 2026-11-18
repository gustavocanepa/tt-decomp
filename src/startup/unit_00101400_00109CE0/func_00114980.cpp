#include "types.h"

struct V { short delta; short index; void *fn; };
struct Src { char pad[0x64]; char *tbl; };
struct Dst { char pad[0x4B8]; s32 f4B4; };

extern "C" void func_00114980(Dst *arg0, Src *arg1) {
    s32 loc;
    V *e = (V *)(arg1->tbl + 0x310);
    s32 r = ((s32 (*)(void *, void *))e->fn)((char *)arg1 + e->delta, &loc);
    arg0->f4B4 = 0;
    if (r == 9) {
        arg0->f4B4 = 1;
    }
    if (r == 6 && (unsigned int)(loc - 6) < 2) {
        arg0->f4B4 = 1;
    }
}
