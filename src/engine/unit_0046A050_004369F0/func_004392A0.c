#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00601290[], D_00601298[], D_006012A0[], D_006012A8[];
struct func_004392A0_p {
    char pad0[0x8];
    s32 unk8;
};

char *func_004392A0(struct func_004392A0_p *p) {
    switch (p->unk8) {
    case 0: return D_00601290;
    case 1: return D_00601298;
    case 2: return D_006012A0;
    default: return D_006012A8;
    }
}
