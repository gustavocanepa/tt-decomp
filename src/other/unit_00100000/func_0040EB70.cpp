typedef int s32;

struct Obj {
    char pad[0xB4];
    void *unk14;
};

extern "C" char D_005D97E8;
extern "C" void func_0040EF20(Obj *arg0, s32 arg1);
extern "C" void func_0050E1A8(Obj *arg0);

extern "C" void func_0040EB70(Obj *arg0, s32 arg1) {
    arg0->unk14 = &D_005D97E8;
    func_0040EF20(arg0, arg1);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
