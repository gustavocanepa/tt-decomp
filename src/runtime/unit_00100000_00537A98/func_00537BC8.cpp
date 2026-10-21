#include "types.h"

struct Node {
    char pad[0xC];
    struct Node *unkC;
};

extern "C" s32 D_0057B4D0;

extern "C" s32 func_00537BC8(struct Node *arg0) {
    if (arg0 != 0) {
        arg0->unkC = (struct Node *)D_0057B4D0;
        D_0057B4D0 = (s32)arg0;
    }
    return D_0057B4D0;
}
