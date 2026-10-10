#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern s32 D_00586A68;
struct func_001F2AF0_p {
    char pad0[0xD8];
    s32 unkD8;
};

s32 func_001F2AF0(struct func_001F2AF0_p *p) {
    if (p->unkD8 != 0) {
        switch (D_00586A68) {
        case 0: case 9: case 10: case 11:
            return 0;
        default:
            return 1;
        }
    }
    return 0;

}
