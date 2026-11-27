#include "types.h"
struct NameValue {
    const char *name;
    s32 value;
};
extern "C" s32 func_004A8268(const char *left, const char *right);
extern "C" s32 func_004C9E58(NameValue *entry, const char *name) {
    s32 value;
    if (func_004A8268(entry->name, name) != 0)
        value = 0;
    else
        value = entry->value;
    return value;
}
