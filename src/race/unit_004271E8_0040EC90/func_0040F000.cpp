#include "types.h"
struct O { char pad[0xB0]; char *tab; };
extern "C" int SPEC_DATABASE__RaceSpec__getEnemyCount(void *);
extern "C" s64 func_0040F000(O *self, int i) {
    int ok = i < SPEC_DATABASE__RaceSpec__getEnemyCount(self);
    i = i * 2 + 2;
    s64 r = -1;
    if (!ok) return r;
    r = *(s64 *)((i * 8) + self->tab);
    return r;
}
