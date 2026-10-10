typedef int s32;

extern "C" int func_003F6350(void *arg0, void *arg1, void *arg2, s32 arg3);

extern "C" int func_003F63B8(void *arg0, void *arg1) {
    return func_003F6350(arg0, arg1, (char *)arg0 + 0x2008, 0x80);
}
