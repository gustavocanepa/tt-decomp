#include "types.h"

struct VEntry0037BDF8 {
    s16 delta;
    s16 index;
    void *(*fn)(void *);
};

struct ObjInner0037BDF8 {
    char pad0[8];
    VEntry0037BDF8 *vtbl;
};

struct Result0037BDF8 {
    char pad0[0x40];
    s32 unk40;
};

struct Mid0037BDF8 {
    char pad0[0x4840];
    ObjInner0037BDF8 *unk2880;
};

struct Obj0037BDF8 {
    char pad0[0x190];
    Mid0037BDF8 *unk18C;
};

extern "C" s32 func_00325078(struct Obj0037BDF8 *arg0) {
    ObjInner0037BDF8 *a1 = arg0->unk18C->unk2880;
    VEntry0037BDF8 *e = &a1->vtbl[11];
    struct Result0037BDF8 *r = (struct Result0037BDF8 *)e->fn((char *)a1 + e->delta);

    return r->unk40;
}
