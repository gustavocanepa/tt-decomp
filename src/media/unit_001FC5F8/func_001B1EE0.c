typedef int s32;
s32 func_001D2508(char *a, s32 b, s32 c, s32 d);
void func_004BBD18(s32 a, char *b, s32 c);
void func_001B1EE0(char *arg0, s32 arg1) {
    char sp[0x80];
    func_001D2508(sp, 0x80, arg1, 0);
    func_004BBD18(*(s32 *)(arg0 + 0xE4), sp, 0x500000);
    *(s32 *)(arg0 + 0x10C) = 1;
}
