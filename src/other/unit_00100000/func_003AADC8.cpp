typedef int s32;

struct Obj {
    char pad[0x14];
    void *unk14;
};

extern "C" char D_005D6E30;
extern "C" void func_003AAE28(Obj *arg0, s32 arg1);
extern "C" void func_0050E1A8(Obj *arg0);

extern "C" void func_003AADC8(Obj *arg0, s32 arg1) {
    arg0->unk14 = &D_005D6E30;
    func_003AAE28(arg0, arg1);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
