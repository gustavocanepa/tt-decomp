#include "types.h"

struct Entry {
    s32 key;
    void *value;
};

extern "C" void *func_001566C0(Entry *e, s32 key) {
    for (; e->value != 0; e++) {
        if (e->key == key)
            return e->value;
    }
    return 0;
}
