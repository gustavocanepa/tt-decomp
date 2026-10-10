typedef int s32;

struct Obj {
    char pad[0x12C8];
    s32 unk12C8;
};

extern "C" void func_004207A0(s32 arg0, s32 arg1);

extern "C" void func_003D1138(struct Obj *arg0) {
    func_004207A0(arg0->unk12C8, 0);
}
