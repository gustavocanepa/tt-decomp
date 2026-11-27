#include "types.h"

struct Key {
    f32 pos;
    f32 value;
};

struct Table {
    int unk0;
    u16 count;
    Key *keys;
};

extern "C" f32 func_003F4F68(Table *t, f32 lo, f32 hi) {
    for (int i = 0; i < t->count; i++) {
        Key *k = &t->keys[i];
        if (lo <= k->pos && k->pos <= hi)
            return k->value;
    }
    return 0.0f;
}
