typedef int s32;
typedef unsigned char u8;

extern "C" void func_0035D5F0(char *arg0, u8 arg1) {
    s32 *p = (s32 *)(arg0 + 0x274);
    *p = (*p & ~0xFF) | arg1;
}
