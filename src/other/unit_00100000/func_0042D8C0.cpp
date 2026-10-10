typedef int s32;

struct Obj00462588 {
    s32 unk0;
    char pad[0x10 - 4];
    s32 unk10;
};

extern s32 D_00585F28;

extern "C" s32 func_0042D8C0(struct Obj00462588 *arg0) {
    return (arg0->unk0 == 0) ? D_00585F28 : arg0->unk10;
}
