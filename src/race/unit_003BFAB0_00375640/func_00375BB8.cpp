#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" {
void func_0037BD40(s32 *arg0);              /* extern */
void func_00370880(char *arg0);             /* extern */

struct func_00375BB8_list {
    s32 count;
    char pad4[4];
    s32 items;
};

void func_00375BB8(char *arg0) {
    s32 i;
    s32 temp_v0;
    s32 items;
    struct func_00375BB8_list *l;

    func_0037BD40((s32 *)(arg0 + 0x920));
    func_0037BD40((s32 *)(arg0 + 0x924));
    i = 0;
    func_00370880(arg0 + 0x928);
    l = *(struct func_00375BB8_list **)(arg0 + 0x60);
    if (l->count > 0) {
        items = l->items;
        do {
            temp_v0 = i * 4;
            i += 1;
            func_00370880((char *)(*(s32 *)(temp_v0 + items)) + 0x1220);
            l = *(struct func_00375BB8_list **)(arg0 + 0x60);
            if (!(i < l->count)) {
                break;
            }
            items = l->items;
        } while (1);
    }
}

}
