#include "types.h"

struct Key_001D1478 {
    u64 id : 56;
    u64 kind : 8;
};

extern "C" u64 func_0019CC58(void *src);
extern "C" unsigned char func_0019CC78(void *src);

extern "C" void func_00198738(Key_001D1478 *key, char *src) {
    key->id = func_0019CC58(src);
    key->kind = func_0019CC78(src + 0x24);
}
