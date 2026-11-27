#include "types.h"

struct Rec {
    s64 value;
    s64 pad;
};

extern char D_00585A30[];
extern "C" u64 func_0040CFE0(void *arg);
extern "C" bool func_0040B940(void *db, int key, int type, Rec *out);

extern "C" s64 func_0040D308(void *arg) {
    u64 id = func_0040CFE0(arg) & 0xFFFFFFFF;
    Rec rec;
    if (func_0040B940(D_00585A30, id, 0x29, &rec))
        return rec.value;
    return -1;
}
