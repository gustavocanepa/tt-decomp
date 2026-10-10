typedef int s32;

extern "C" void func_001E6428(void *arg0, s32 arg1);
extern "C" void func_001E6480(void *arg0);
extern "C" s32 func_001E7040(s32 arg0);
extern "C" void func_0029CEF0(s32 *arg0, s32 arg1);
extern "C" void func_0029EA18(s32 *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_001E6C38(s32 *arg0) {
    s32 sp[4];
    s32 sp10[4];
    s32 *p1;
    s32 temp_a0;
    s32 temp_s0;

    func_001E6480(sp);
    {
        s32 t = func_001E7040(sp[0]);
        p1 = sp10;
        func_0029EA18(p1, t);
    }
    if (arg0 != p1) {
        temp_s0 = *p1;
        if (temp_s0 != 0) {
            func_002C0FE8(temp_s0);
        }
        temp_a0 = *arg0;
        if (temp_a0 != 0) {
            func_002C1050(temp_a0);
        }
        *arg0 = temp_s0;
    }
    func_0029CEF0(p1, 2);
    func_001E6428(sp, 2);
}
