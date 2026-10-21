#include "types.h"

struct Elem {
    char pad[0xC];
    s32 unkC;
};

extern "C" s32 func_0055C968(char *arg0, s32 arg1, s32 arg2) {
    Elem *entry = (Elem *)(arg0 + ((arg1 * 4 + arg2) * 4));
    return entry->unkC;
}
