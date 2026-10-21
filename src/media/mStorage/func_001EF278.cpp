#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

extern "C" void *func_001EF140(s32 *arg0, void *arg1);
extern "C" void func_001EEF48(void *arg0, s32 *arg1);
extern "C" void func_001EEF60(void *arg0, int arg1);
extern "C" void func_001EEF30(void *arg0, s32 *arg1);

extern "C" void *func_001EF278(void *arg0) {
    s32 sp[8];
    s32 i = 0;
    do {
        func_001EF140(sp, (void *)i);
        i++;
        VObj *o = (VObj *)sp[0];
        VEntry *e = (VEntry *)(o->vtbl + 0x1B8);
        s32 r = e->fn((char *)o + e->delta);
        if (r != 0) {
            func_001EEF48(arg0, sp);
            func_001EEF60(sp, 2);
            return arg0;
        }
        func_001EEF60(sp, 2);
    } while (i < 3);
    sp[4] = 0;
    func_001EEF30(arg0, &sp[4]);
    return arg0;
}
