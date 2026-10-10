typedef int s32;

struct Obj002872C8 {
    char pad[0x20];
    s32 unk20;
};

extern "C" void mTransition__virtual_49(Obj002872C8 *arg0);

extern "C" void func_00227910(Obj002872C8 *arg0) {
    mTransition__virtual_49(arg0);
    arg0->unk20 = 0;
}
