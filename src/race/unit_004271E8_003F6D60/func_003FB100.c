#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { s16 d; s16 pad; s32 (*fn)(void *); } E;
void func_00400CF0(s32);
void func_003FB100(s8 *arg0) {
    s8 *p = arg0 + 8;
    s32 i = 999;
    s32 sum = 0;
    do {
        E *e = (E *)(*(s8 **)p + 0x10);
        i -= 1;
        sum += e->fn(p + e->d);
        p += 0x508;
    } while (i >= 0);
    func_00400CF0(sum);
}
