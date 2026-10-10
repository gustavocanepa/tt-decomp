typedef int s32;

struct Obj002872C8 {
    char pad[0x20];
    s32 unk20;
};

extern "C" void func_001FC480(Obj002872C8 *arg0);

extern "C" void func_00227968(Obj002872C8 *arg0) {
    func_001FC480(arg0);
    arg0->unk20 = 0;
}
