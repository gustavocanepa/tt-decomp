typedef int s32;

struct S001032F0 {
    char pad0[0x1A8];
    s32 unk68;
};

extern "C" void func_00484558(void *arg0);

extern "C" void func_002486D8(S001032F0 *arg0, s32 arg1) {
    arg0->unk68 = arg1;
    func_00484558((char *)arg0 + 0x5B8);
}
