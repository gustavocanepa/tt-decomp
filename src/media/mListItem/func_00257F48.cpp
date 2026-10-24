#include "types.h"

struct Item_002B5438 {
    char pad[0x1C];
    s16 m1C;
};

extern "C" s32 func_002571D8(void *list);
extern "C" Item_002B5438 *func_002571B8(void *list, s32 i);

extern "C" void func_00257F48(void *list, s32 i, s32 value) {
    if (i >= 0 && i < func_002571D8(list)) {
        func_002571B8(list, i)->m1C = value;
    }
}
