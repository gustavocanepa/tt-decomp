typedef int s32;

extern "C" void func_003F7598(void *arg0) {
    char *self = (char *)arg0;
    s32 n = *(s32 *)(self + 0xB28);
    *(s32 *)(self + 0xC6C) = n;
    __builtin_memcpy(self + 0xC70, self + 0xB2C, 0x100);
}
