#include "types.h"

struct Node {
    char *obj;
    s32 pad4;
    Node *next;
};

struct VEntry2 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct VEntry4 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32, s32, s32);
};

extern char D_0058C558[];
extern Node *D_0058C588;

extern "C" void func_004A4D68(s32 a0);
extern "C" void func_004A4DD8(s32 a0);

extern "C" s32 func_0047C7C0(s32 arg0, s32 arg1, s32 arg2) {
    s32 r = -1;
    Node *n;
    char *o;

    func_004A4D68((s32)D_0058C558);
    n = D_0058C588;
    if (n != 0) {
        do {
            o = n->obj;
            VEntry2 *e = (VEntry2 *)(*(char **)(o + 0xA4) + 0x38);
            if (e->fn(o + e->delta, arg0) != 0) {
                VEntry4 *e4 = (VEntry4 *)(*(char **)(o + 0xA4) + 0x48);
                r = e4->fn(o + e4->delta, arg0, arg1, arg2);
                break;
            }
            n = n->next;
        } while (n != 0);
    }
    func_004A4DD8((s32)D_0058C558);
    return r;
}
