typedef int s32;

struct Obj3E06F8 {
    char pad[0x4];
    s32 unk4;
};

extern "C" s32 func_0037ED08(Obj3E06F8 *arg0, s32 arg1) {
    return arg1 == arg0->unk4;
}
