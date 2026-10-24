#include "types.h"

struct Seed_00435A10 {
    u64 a;
    u64 b;
};

struct Obj_00435A10 {
    char pad0[0x8214];
    s32 m81CC;
    char pad8218[0x8228 - 0x8218];
    s32 m81F0;
    char pad822C[0x8238 - 0x822C];
    s32 m81E0;
};

extern "C" u64 func_004B6658(void);
extern "C" u64 func_004A5A30(void);
extern "C" s32 func_004A9888(void *data, s32 size);

extern "C" void func_003FBFF8(Obj_00435A10 *o) {
    Seed_00435A10 seed;
    seed.a = func_004B6658();
    seed.b = func_004A5A30();
    o->m81CC = func_004A9888(&seed, sizeof(seed));
    o->m81F0 = 0;
    o->m81E0 = 0;
}
