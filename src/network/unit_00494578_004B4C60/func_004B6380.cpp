/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct G {
    s32 unk0;
    char pad4[0x38];
    s32 unk3C;
    char pad40[0x40];
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    char pad90[0x30];
    char unkC0[0x40];
};
extern G D_00774100;
extern s32 D_00598334;
extern "C" void func_004F43A8(s32, s32);
extern "C" s32 func_004F45D8(void *, s32, s32, void *, s32);
extern "C" void func_004F42C8(s32);
extern "C" void func_004F4348(s32);
extern "C" void func_004B6380(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_004F4348(D_00598334);
    func_004F4348(D_00774100.unk0);
    D_00774100.unk3C = 1;
    D_00774100.unk80 = arg1;
    D_00774100.unk8C = arg3;
    D_00774100.unk84 = arg2;
    D_00774100.unk88 = arg0;
    func_004F43A8(arg0, arg2);
    func_004F45D8(&D_00774100, 3, 1, D_00774100.unkC0, 0x40);
    func_004F42C8(D_00598334);
}
