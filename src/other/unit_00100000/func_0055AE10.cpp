typedef int s32;

struct Obj005FBAF8 {
    char pad[0x80];
    s32 unk80;
};

extern "C" void func_0034A9B0(s32 arg0);

extern "C" void func_0055AE10(struct Obj005FBAF8 *arg0) {
    func_0034A9B0(arg0->unk80);
}
