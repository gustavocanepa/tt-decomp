typedef int s32;

struct Obj {
    char pad0[0x11D4];
    s32 unk70;
};

extern "C" void func_00457F18(Obj *arg0);

extern "C" void func_003EE3B0(Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00457F18(arg0);
    arg0->unk70 = arg3;
}
