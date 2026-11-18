#include "types.h"

struct Node_004AEF48 {
    char *obj;
    char pad4[4];
    Node_004AEF48 *next;
};

struct VEntryF_004AEF48 {
    s16 delta;
    s16 index;
    f32 (*fn)(char *);
};

extern "C" void func_004A4D68(char *a0);
extern "C" void func_004A4DD8(char *a0);

extern "C" f32 func_0047E868(char *arg0) {
    s32 cnt;
    Node_004AEF48 *node;
    f32 acc;

    cnt = 0;
    func_004A4D68(arg0);
    node = *(Node_004AEF48 **)(arg0 + 0xAC);
    acc = 0.0f;
    while (node != 0) {
        char *obj = node->obj;
        cnt++;
        char *vt = *(char **)(obj + 0xA8);
        VEntryF_004AEF48 *e = (VEntryF_004AEF48 *)(vt + 0x28);
        f32 f = e->fn(obj + e->delta);
        node = node->next;
        acc += f;
    }
    if (cnt != 0) {
        acc = acc / (f32)cnt;
    }
    func_004A4DD8(arg0);
    return acc;
}
