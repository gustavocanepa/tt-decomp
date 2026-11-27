#include "types.h"

struct Clock { char pad[0x80]; u32 now; };
extern struct Clock D_00774200;
void func_004F43A8(u32 *, int);

u64 func_004B65E8(void) {
    struct Clock *c = &D_00774200;
    func_004F43A8(&c->now, 0x40);
    return (u64)c->now + 0x31510F5B40UL;
}
