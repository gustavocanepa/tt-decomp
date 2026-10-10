typedef int s32;

struct Obj {
    char pad[0x94];
    s32 unk94;
};

extern "C" void func_0042D9A8(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_0042DB00(s32 arg0, Obj *arg1) {
    func_0042D9A8(arg0, arg1->unk94, 0);
}
