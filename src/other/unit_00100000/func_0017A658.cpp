typedef int s32;

struct Obj {
    char pad[0x5C];
    s32 unk5C;
};

extern "C" void func_0017A610(Obj *arg0);

extern "C" void func_0017A658(Obj *arg0, s32 arg1) {
    arg0->unk5C = arg1;
    func_0017A610(arg0);
}
