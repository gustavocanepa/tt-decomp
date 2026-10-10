typedef int s32;

extern "C" void func_00423F08(void *arg0, s32 *arg1, s32 arg2);

extern "C" s32 func_00423E58(void *arg0) {
    s32 local;
    func_00423F08(arg0, &local, 4);
    return local;
}
