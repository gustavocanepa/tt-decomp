typedef int s32;

extern "C" void func_004D9EA8(s32 arg0);

extern "C" void func_00101568(s32 (*arg0)(void)) {
    func_004D9EA8(arg0());
}
