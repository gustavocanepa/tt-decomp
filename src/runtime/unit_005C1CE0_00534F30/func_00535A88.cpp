#include "types.h"

struct Node {
    char pad[0xC];
    struct Node *unkC;
};

extern "C" struct Node *D_0057B308;

extern "C" struct Node *func_00535A88(struct Node *arg0) {
    if (arg0 != 0) {
        arg0->unkC = D_0057B308;
        D_0057B308 = arg0;
    }
    return D_0057B308;
}
