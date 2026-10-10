typedef int s32;

extern "C" s32 func_004A45F8(s32 arg0);
extern "C" void func_001325C8(s32 arg0, s32 arg1);
extern "C" void func_002A7578(s32 arg0, s32 *arg1);

extern "C" void func_00132838(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    s32 s1 = arg1;
    s32 s2 = func_004A45F8(0x198);
    func_001325C8(s2, s1);
    s32 local = s2;
    func_002A7578(s0, &local);
}
