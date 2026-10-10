#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_006012D0[], D_006012D8[], D_006012E0[], D_006012E8[];
struct func_00439370_p {
    char pad0[0x10];
    s32 unk10;
};

char *func_00439370(struct func_00439370_p *p) {
    switch (p->unk10) {
    case 0: return D_006012D0;
    case 1: return D_006012D8;
    case 2: return D_006012D8;
    case 3: return D_006012E0;
    default: return D_006012E8;
    }
}
