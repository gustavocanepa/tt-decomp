typedef int s32;

struct Obj {
    volatile s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    char pad10[0x14];
    s32 unk24;
    char pad28[0x4];
    s32 unk2C;
};

extern "C" s32 func_00576A50(Obj *arg0) {
    s32 a;
    s32 b;

    if (arg0->unk0 & 0x100) {
        a = arg0->unk24;
    } else {
        a = arg0->unkC;
    }
    if (arg0->unk0 & 0x100) {
        b = arg0->unk2C;
    } else {
        b = arg0->unk8;
    }
    return a != b;
}
