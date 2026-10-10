typedef int s32;

struct Obj003D57D8 {
    char pad0[0x12C8];
    s32 unk12C8;
};

extern "C" void func_00420900(s32 arg0);

extern "C" void func_003D1270(struct Obj003D57D8 *arg0) {
    func_00420900(arg0->unk12C8);
}
