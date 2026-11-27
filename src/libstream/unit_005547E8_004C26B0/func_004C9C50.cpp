#include "types.h"

struct S { char pad[4]; u16 unk4; };

extern "C" void *func_004C9C50(S *arg0) {
    char *p = (char *)arg0 + 4;
    return p + *(u16 *)p;
}
