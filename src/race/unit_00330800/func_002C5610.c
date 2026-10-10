typedef int s32;
void func_004F6678(s32 a, s32 b, s32 c);
void func_002C52C0(s32 a, s32 b, s32 c);
void func_002C5610(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_004F6678(arg2, 0, arg3);
    while (arg1 > 0) {
        s32 n = arg3 < arg1 ? arg3 : arg1;
        arg1 -= arg3;
        func_002C52C0(arg0, arg2, n);
    }
}
