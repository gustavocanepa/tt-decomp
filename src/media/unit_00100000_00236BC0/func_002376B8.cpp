typedef int s32;

extern "C" void func_002372F8(void *arg0, s32 arg1);
extern "C" void func_00237350(void *arg0);
extern "C" s32 func_002375C0(s32 arg0);
extern "C" void func_002ADBF0(s32 *arg0, s32 arg1);
extern "C" void func_002B01F8(s32 *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_002376B8(s32 *arg0) {
    s32 sp[4];
    s32 sp10[4];
    s32 *p1;
    s32 temp_a0;
    s32 temp_s0;

    func_00237350(sp);
    {
        s32 t = func_002375C0(sp[0]);
        p1 = sp10;
        func_002B01F8(p1, t);
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
    func_002ADBF0(p1, 2);
    func_002372F8(sp, 2);
}
