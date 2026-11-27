#include "types.h"

struct File { void *fd; char pad[0x16]; u8 flags; };
int func_004E7B20(void *, int, int);

struct File **func_004E29F0(struct File **h, int mode) {
    if (func_004E7B20((*h)->fd, mode, 1) == -1)
        (*h)->flags |= 4;
    return h;
}
