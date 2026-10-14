typedef int s32;

struct Obj {
    char pad[0x34];
    s32 unk34;
    char pad2[0x38 - 0x34 - 4];
    s32 unk38;
};

extern "C" void func_0034CFA0(Obj *arg0, s32 arg1, s32 arg2);

extern "C" void func_0034CF48(Obj *arg0, s32 arg1) {
    s32 v = (arg1 != 0) ? arg0->unk38 : 0;
    func_0034CFA0(arg0, arg0->unk34, v);
}
