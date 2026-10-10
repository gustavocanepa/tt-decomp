typedef int s32;

extern "C" void func_003F6238(void *arg0, void *arg1, void *arg2, s32 arg3);

extern "C" void func_003F6308(void *arg0, void *arg1) {
    func_003F6238(arg0, arg1, (char *)arg0 + 0x2008, 0x80);
}
