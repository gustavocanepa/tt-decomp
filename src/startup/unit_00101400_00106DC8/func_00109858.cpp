typedef int s32;

extern "C" void func_004A4D68(s32 a0);
extern "C" void func_004A4DD8(s32 a0);
extern "C" void func_004A4F90(s32 a0);

extern "C" void func_00109858(s32 arg0) {
    s32 s0 = arg0 + 0x6C;

    func_004A4D68(s0);
    func_004A4F90(s0);
    func_004A4DD8(s0);
}
