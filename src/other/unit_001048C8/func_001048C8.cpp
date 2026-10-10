typedef int s32;
typedef float f32;

struct Obj {
    char pad0[4];
    s32 unk4;
    char pad1[0x18];
    f32 unk20;
    f32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
};

extern "C" s32 func_00104A48(void *arg0, s32 arg1, s32 arg2);
extern "C" s32 func_00104B10(Obj *arg0);

extern "C" s32 func_001048C8(Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unk4 = arg1;
    func_00104A48(arg0, arg2, arg3);
    arg0->unk20 = 0.5f;
    arg0->unk28 = 0;
    arg0->unk24 = 0.5f;
    arg0->unk2C = 0;
    arg0->unk30 = 0;
    arg0->unk34 = 0;
    arg0->unk38 = 0;
    return func_00104B10(arg0);
}
