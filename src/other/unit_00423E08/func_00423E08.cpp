typedef int s32;
typedef short s16;

extern "C" void func_00423F08(s32 arg0, char *arg1, s32 arg2);

extern "C" s16 func_00423E08(s32 arg0) {
    s16 local;
    func_00423F08(arg0, (char *)&local, 2);
    return local;
}
