typedef short s16;

struct VEntry0013ACC8 {
    s16 delta;
    s16 index;
    void (*fn)(void *, int);
};

struct Sub0013ACC8 {
    char pad0[0x4];
    VEntry0013ACC8 *vtbl;
};

struct Obj0013ACC8 {
    char pad0[0x308];
    Sub0013ACC8 *unk2A4;
    char pad1[0xC];
    int unk2B4;
};

extern "C" void func_00127040(struct Obj0013ACC8 *arg0, int arg1) {
    arg0->unk2B4 = arg1;

    Sub0013ACC8 *a2 = arg0->unk2A4;

    if (a2 != 0) {
        VEntry0013ACC8 *e = (VEntry0013ACC8 *)((char *)a2->vtbl + 0x270);
        e->fn((char *)a2 + e->delta, arg1);
    }
}
