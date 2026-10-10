#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005B4028[];
s32 func_001CFF18(void *);
struct mMoviePS2__structor_0_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

void mMoviePS2__structor_0(struct mMoviePS2__structor_0_arg0 *arg0) {
    func_001CFF18(arg0);
    arg0->unk4 = (s32)D_005B4028;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
}
