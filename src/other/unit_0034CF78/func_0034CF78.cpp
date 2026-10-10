typedef int s32;

struct Obj {
    char pad[0x44];
    s32 unk44;
    s32 unk48;
};

extern "C" void func_0034CFA0(Obj *arg0, s32 arg1, s32 arg2);

extern "C" void func_0034CF78(Obj *arg0) {
    func_0034CFA0(arg0, arg0->unk44, arg0->unk48);
}
