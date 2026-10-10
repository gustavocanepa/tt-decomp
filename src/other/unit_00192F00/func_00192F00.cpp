typedef int s32;

extern "C" s32 func_004105D0(s32 *arg0);
extern "C" void func_0029EA18(s32 *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_0029CEF0(s32 *arg0, s32 arg1);

extern "C" void func_00192F00(s32 *arg0) {
    s32 buf[4];
    s32 temp_v0;

    func_0029EA18(buf, func_004105D0(arg0));
    if (arg0 != buf) {
        s32 s0 = buf[0];
        if (s0 != 0) {
            func_002C0FE8(s0);
        }
        temp_v0 = *arg0;
        if (temp_v0 != 0) {
            func_002C1050(temp_v0);
        }
        *arg0 = s0;
    }
    func_0029CEF0(buf, 2);
}
