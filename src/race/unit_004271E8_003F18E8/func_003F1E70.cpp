#include "types.h"

struct Arr { u16 n; u16 data[1]; };
struct Self { char pad[0x14]; Arr *m14; };
extern "C" s32 func_00560B68(u16 *, u16 *, s16 *);

extern "C" s32 func_003F1E70(Self *self, s16 v) {
    s16 key = v;
    Arr *a = self->m14;
    if (a == 0) return 1;
    {
        u16 *b = a->data;
        return func_00560B68(b, b + a->n, &key);
    }
}
