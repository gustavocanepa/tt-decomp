typedef int s32;
typedef unsigned short u16;

extern "C" void func_00423F08(s32 arg0, char *arg1, s32 arg2);

extern "C" u16 func_00423DE0(s32 arg0) {
    u16 local;
    func_00423F08(arg0, (char *)&local, 2);
    return local;
}
