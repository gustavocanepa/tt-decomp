typedef int s32;

extern "C" void func_004F8588(void *arg0, void *arg1, s32 arg2);

extern "C" void func_00401798(void *arg0, void *arg1) {
    func_004F8588((char *)arg0 + 0x30, arg1, 0x10);
}
