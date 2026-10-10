typedef int s32;

extern "C" void func_00423D40(void *arg0, s32 *arg1, s32 arg2);

extern "C" void func_00423C88(void *arg0, s32 arg1) {
    s32 local = arg1;
    func_00423D40(arg0, &local, 4);
}
