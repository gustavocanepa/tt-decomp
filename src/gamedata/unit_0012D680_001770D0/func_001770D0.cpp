#include "types.h"
struct Entry { char label[64]; float score; };
extern "C" s32 func_001770D0(Entry *entries, s32 low, s32 high, float score) {
    s32 middle = (low + high) / 2;
    if (middle == low) return middle;
    if (entries[middle].score < score) return func_001770D0(entries, low, middle, score);
    return func_001770D0(entries, middle, high, score);
}
