#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_006012A8[], D_006012B0[], D_006012B8[], D_006012C0[], D_006012C8[];
struct func_00439300_p {
    char pad0[0xC];
    s32 unkC;
};

char *func_00439300(struct func_00439300_p *p) {
    switch (p->unkC) {
    case 0: return D_006012B0;
    case 1: return D_006012B8;
    case 2: return D_006012C0;
    case 3: return D_006012C8;
    default: return D_006012A8;
    }
}
