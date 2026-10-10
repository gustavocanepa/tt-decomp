typedef int s32;

struct Obj002872C8 {
    char pad[0x20];
    s32 unk20;
};

extern "C" void mTransition__panOutIn(Obj002872C8 *arg0);

extern "C" void func_00227968(Obj002872C8 *arg0) {
    mTransition__panOutIn(arg0);
    arg0->unk20 = 0;
}
