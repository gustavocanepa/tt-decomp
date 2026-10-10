typedef int s32;

struct Obj {
    char pad[0xC];
    s32 unkC;
    s32 unk10;
};

extern "C" void func_00108738(s32 arg0, struct Obj *arg1);

extern "C" void func_00108860(struct Obj *arg0, s32 arg1) {
    arg0->unk10 = arg1;
    func_00108738(arg0->unkC, arg0);
}
