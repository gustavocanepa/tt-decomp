typedef int s32;
extern "C" void func_003FFB00(char *a, s32 b, s32 c);
extern "C" void func_003FD938(char *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x14) = arg1;
    func_003FFB00(arg0 + 0x24, arg1, *(s32 *)(arg0 + 0x13F0) == 1);
}
