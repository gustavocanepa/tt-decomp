#include "types.h"

extern "C" f32 func_002E4680(u32 *total, f32 amount) {
    int whole = (int)amount;
    if (amount <= 0.0f)
        return 0.0f;
    *total += whole;
    if (*total > 1599999999) {
        *total = 1600000000;
        return 0.0f;
    }
    return amount - whole;
}
