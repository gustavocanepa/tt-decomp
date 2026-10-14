typedef int s32;
typedef float f32;

struct Obj_003FDB18_s0 {
    char pad0[0x34];
    s32 unk34;
    f32 *unk38;
};

struct Obj_003FDB18_v2 {
    char pad0[0xB0];
    struct Obj_003FDB18_s0 *unkB0;
};

struct Obj_003FDB18_v1 {
    char pad0[0x4];
    struct Obj_003FDB18_v2 *unk4;
};

struct Obj_003FDB18_arg0 {
    char pad0[0x80];
    struct Obj_003FDB18_v1 *unk80;
};

struct Obj_003FDB18_a1 {
    char pad0[0x34];
    f32 unk34;
};

extern "C" f32 func_003A7988(struct Obj_003FDB18_a1 *arg0);

extern "C" s32 func_003A8FA0(struct Obj_003FDB18_arg0 *arg0, struct Obj_003FDB18_a1 *arg1) {
    f32 t20 = arg1->unk34;
    struct Obj_003FDB18_s0 *s0 = arg0->unk80->unk4->unkB0;
    s32 n = s0->unk34;
    f32 f1 = func_003A7988(arg1);
    s32 i;

    if (t20 <= f1)
        return 0;
    if (f1 + 0x1.Ep4f < t20)
        return 0;

    i = 0;
    while (i < n) {
        f32 v = s0->unk38[i];
        i++;
        if (f1 < v && v < t20)
            return 1;
    }
    return 0;
}
