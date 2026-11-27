#include "types.h"

struct Self { char pad[0x23926]; u8 max; char pad2[0x7ED]; s16 cur; };

extern "C" s16 func_00304FE8(Self *self) {
    if (self->cur < self->max) self->cur++;
    return self->cur;
}
