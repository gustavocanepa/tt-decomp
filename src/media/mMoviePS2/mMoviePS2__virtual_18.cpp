#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct MoviePS2 {
    s32 unk0;
    char *vtbl;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

extern "C" s32 mMoviePS2__virtual_18(MoviePS2 *arg0) {
    char *vt = arg0->vtbl;
    if (arg0->unkC == 0) {
        VEntry *e = (VEntry *)(vt + 0x90);
        if (e->fn((char *)arg0 + e->delta) == 0) {
            arg0->unkC = 1;
        }
        return 0;
    }
    VEntry *e = (VEntry *)(vt + 0x90);
    if (e->fn((char *)arg0 + e->delta) != 0) {
        if (arg0->unk10 == 0) {
            arg0->unk10 = 1;
            return 1;
        }
    }
    return 0;
}
