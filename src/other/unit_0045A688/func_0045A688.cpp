typedef int s32;

struct Obj {
    char pad[0x8];
    s32 unk8;
    s32 unkC;
};

extern "C" s32 func_0045A688(Obj *arg0) {
    return arg0->unk8 + (arg0->unkC < 8);
}
