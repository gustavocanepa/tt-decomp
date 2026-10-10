typedef int s32;

extern "C" s32 func_004CC5A8(s32 arg0);
extern "C" void func_004CC668(s32 arg0);

extern "C" s32 func_004CC568(s32 arg0) {
    s32 temp_s1 = func_004CC5A8(arg0);
    func_004CC668(arg0);
    return temp_s1;
}
