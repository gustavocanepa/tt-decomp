/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Clears *out, then, when the object is func_005AE360 (+0x14), looks key up through func_004CEBD8 and
   stores func_004C2CA0(handle of the found slot, a, b) to *out. Returns 3 for a closed object,
   the lookup's status when it fails, else 0. */
#include "types.h"

struct func_004CEFA0_a0 {
    char pad0[0x8];
    s32 handles[3];
    s32 func_005AE360;
    char pad18[0x48];
    s32 table;
};

extern "C" s32 func_004CEBD8(s32 table, s32 key, s32 *slot);
extern "C" s32 func_004C2CA0(s32 handle, s32 a, s32 b);

extern "C" s32 func_004CEFA0(struct func_004CEFA0_a0 *obj, s32 key, s32 a, s32 b, s32 *out) {
    s32 slot;
    *out = 0;
    if (obj->func_005AE360 == 0)
        return 3;
    s32 err = func_004CEBD8(obj->table, key, &slot);
    if (err != 0)
        return err;
    *out = func_004C2CA0(obj->handles[slot], a, b);
    return 0;
}
