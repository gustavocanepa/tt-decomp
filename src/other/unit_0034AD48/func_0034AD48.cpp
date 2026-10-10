typedef int s32;

struct Obj {
    char pad[0x18];
    s32 unk18;
};

extern "C" void func_0041F840(s32 arg0);

extern "C" void func_0034AD48(Obj *arg0, s32 arg1) {
    func_0041F840(arg1);
    arg0->unk18 = arg1;
}
