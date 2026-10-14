typedef int s32;

extern "C" void func_00473A08(s32 arg0, s32 arg1, const char *arg2);
extern "C" void func_00478C98(s32 arg0);
extern "C" void func_0046F0F8(s32 arg0);

extern "C" char D_005847C0[];
extern "C" char D_005847D0[];
extern "C" char D_005847E0[];
extern "C" char D_005847F0[];

extern "C" void func_0038A3F0(void) {
    func_00473A08(0x66, 0, D_005847D0);
    func_00473A08(0x66, 1, D_005847E0);
    func_00473A08(0x66, 4, D_005847F0);
    func_00473A08(0x66, 0xD, D_005847C0);
    func_00478C98(0x65);
    func_0046F0F8(0x66);
    func_00478C98(0x67);
    func_00478C98(0x68);
}
