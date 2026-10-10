#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F8AD8_arg0 {
    char pad0[0x604];
    f32 unk604;
};

f32 func_002F8AD8(struct func_002F8AD8_arg0 *arg0) {
    return arg0->unk604;
}
