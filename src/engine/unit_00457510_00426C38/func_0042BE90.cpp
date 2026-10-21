typedef int s32;

struct Out {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_0042D140(Out *arg0, s32 arg1);

extern "C" s32 func_0042BE90(void) {
    Out sp;
    func_0042D140(&sp, 0xC);
    return sp.unk4;
}
