#include "types.h"

struct func_0047EE88_arg0;

extern "C" void func_004A4D68(s32 a0);
extern "C" void func_004A4DD8(s32 a0);
extern "C" void func_0047EE88(struct func_0047EE88_arg0 *arg0);

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct Sub {
    char pad0[0xA8];
    char *vt;
};

struct Obj {
    char pad0[0xF0];
    Sub *sub;
    char lock[0x64];
    s32 f150;
    s32 f154;
};

extern "C" void func_00179188(Obj *o)
{
    func_004A4D68((s32)o->lock);
    if (o->f150 != 0) {
        Sub *s = o->sub;
        VEntry *e = (VEntry *)(s->vt + 0x18);
        e->fn((char *)s + e->delta);
    }
    if (o->f154 != 0) {
        Sub *s = o->sub;
        o->sub = 0;
        func_004A4DD8((s32)o->lock);
        VEntry *e = (VEntry *)(s->vt + 0x20);
        e->fn((char *)s + e->delta);
        func_004A4D68((s32)o->lock);
        func_0047EE88((struct func_0047EE88_arg0 *)s);
        o->f154 = 0;
    }
    func_004A4DD8((s32)o->lock);
}
