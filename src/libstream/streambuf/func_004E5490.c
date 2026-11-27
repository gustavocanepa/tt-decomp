#include "types.h"

typedef struct Self { char pad[0x10]; s32 m10; s32 m14; char pad2[0x30]; u16 m48; } Self;
s32 func_004E6428(s32, s32, s32);

s32 func_004E5490(Self *self) {
    if (self->m48 != 0) {
        return func_004E6428(self->m48 - 1, self->m10, self->m14 - self->m10);
    }
    return -1;
}
