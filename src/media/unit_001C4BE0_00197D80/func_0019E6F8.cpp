#include "types.h"

struct Struct_001CF2B8 {
    char pad0[0x48];
    u16 unk48;
    char pad48[0xF8 - 0x4A];
};

extern char D_005E6B18[];

extern "C" void *func_0019E6F8(struct Struct_001CF2B8 *arg0) {
    u16 flag = arg0->unk48 & 1;
    if ((flag & 0xFFFF) != 0) {
        return (char *)arg0 + 0x78;
    }
    return D_005E6B18;
}
