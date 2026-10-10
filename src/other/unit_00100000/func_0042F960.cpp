typedef int s32;

struct Obj {
    char pad[0x18];
    void *unk18;
};

extern "C" char D_005D9DE0;
extern "C" void func_0042FA10(Obj *arg0, s32 arg1);
extern "C" void func_0050E1A8(Obj *arg0);

extern "C" void func_0042F960(Obj *arg0, s32 arg1) {
    arg0->unk18 = &D_005D9DE0;
    func_0042FA10(arg0, arg1);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
