#include "types.h"

struct Mgr {
    char lock[0x6C];
    char list[0x30];
    s32 value;
    s32 dirty;
};

extern Mgr D_0061BBC8;
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_004AEAC0(void *);

extern "C" void func_001004F8(s32 value) {
    Mgr *m = &D_0061BBC8;
    func_004A4D68(m);
    func_004AEAC0(m->list);
    m->value = value;
    m->dirty = 1;
    func_004A4DD8(m);
}
