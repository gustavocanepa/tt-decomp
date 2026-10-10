typedef int s32;

struct Obj {
    char pad[0x178];
    s32 unk170;
};

extern "C" void func_00349AC8(Obj *arg0);

extern "C" void func_00349788(Obj *arg0) {
    arg0->unk170 = arg0->unk170 + 1;
    func_00349AC8(arg0);
}
