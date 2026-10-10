typedef int s32;

struct Obj {
    char pad[0x18];
    void *unk18;
};

extern "C" char D_005DAE10;
extern "C" void func_004AD8F0(Obj *arg0, s32 arg1);
extern "C" void func_0050E1A8(Obj *arg0);

extern "C" void func_004AD890(Obj *arg0, s32 arg1) {
    arg0->unk18 = &D_005DAE10;
    func_004AD8F0(arg0, arg1);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
