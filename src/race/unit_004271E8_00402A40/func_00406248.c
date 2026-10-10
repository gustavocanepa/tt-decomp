#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_00406248_arg0 {
    char pad0[0x4D8];
    s32 unk4D8;
};

u8 func_00406248(void *arg0) {
    return M2C_FIELD(((((struct func_00406248_arg0 *)arg0)->unk4D8 * 0x190) + arg0), u8 *, 0x138);
}
