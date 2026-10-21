#include "types.h"

struct Bits_0044BFE8 {
    u8 *data;
    u32 size;
};

extern "C" Bits_0044BFE8 *func_00414870(Bits_0044BFE8 *bits) {
    if (bits->size == 0) {
        return bits;
    }
    u32 carry = 0;
    u32 i;
    for (i = 0; i < bits->size; i++) {
        u32 v = bits->data[i];
        bits->data[i] = carry | (v << 1);
        carry = v >> 7;
    }
    return bits;
}
