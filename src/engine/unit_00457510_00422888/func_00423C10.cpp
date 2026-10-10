typedef short s16;
typedef int s32;

extern "C" void func_00423D40(void *arg0, s16 *arg1, s32 arg2);

extern "C" void func_00423C10(void *arg0, s16 arg1) {
    s16 local = arg1;
    func_00423D40(arg0, &local, 2);
}
