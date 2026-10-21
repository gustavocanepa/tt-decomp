typedef int s32;
typedef short s16;

struct S;
struct Obj;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Obj {
    char pad0[0x4C];
    char *vt;
};

struct Q {
    char pad0[0x50];
    S *f50;
};

struct S {
    char pad0[0x34];
    Obj *slots[0x190];
    s32 f674;
    char pad1[4];
    Q *p67C;
    s32 f680;
    s32 f684;
    char pad2[0x14];
    s32 f69C;
    char pad3[0x28];
    s32 f6C8;
    s32 f6CC;
};

extern "C" void func_001986F8(S *arg0);

extern "C" void func_00198C98(S *self) {
    self->f680 = -1;
    Q *q = self->p67C;
    self->f6CC = 0;
    self->f69C = 0;
    self->f6C8 = 0;
    if (q != 0) {
        S *t = q->f50;
        if (t != 0) {
            func_001986F8(t);
        }
    }
    s32 n = self->f674;
    self->f674 = 0;
    if (n > 0) {
        s32 i = n - 1;
        if (i >= 0) {
            Obj **e = (Obj **)(i * 4 + (int)self + 0x34);
            do {
                Obj *a2 = *e;
                if (a2 != 0) {
                    VEntry *ent = (VEntry *)(a2->vt + 8);
                    ent->fn((char *)a2 + ent->delta, 3);
                }
                i = i - 1;
                *e = 0;
                e--;
            } while (i >= 0);
        }
    }
    self->f684 = 0;
}
