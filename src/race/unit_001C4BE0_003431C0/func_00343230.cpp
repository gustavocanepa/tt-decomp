typedef int s32;

struct S0038F8A0 {
    char pad0[0x94];
    s32 unk94;
};

extern "C" void func_00344270(void *arg0, s32 arg1);

extern "C" void func_00343230(void *arg0, S0038F8A0 *arg1) {
    func_00344270(arg0, arg1->unk94);
}
