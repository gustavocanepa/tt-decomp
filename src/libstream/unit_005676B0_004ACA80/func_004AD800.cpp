#include "types.h"

struct Table {
    char pad[0x48];
    s32 sorted;
    void *entries;
    s32 count;
};

extern "C" s32 func_004ACE68(const void *, const void *);
extern "C" void func_004F6998(void *, s32, s32, s32 (*)(const void *, const void *));

extern "C" void func_004AD800(Table *t) {
    if (t->sorted != 1) {
        t->sorted = 1;
        func_004F6998(t->entries, t->count, 8, func_004ACE68);
    }
}
