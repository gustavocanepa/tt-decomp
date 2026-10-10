typedef int s32;

extern "C" void func_001F90D8(void *buf);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_001F8C78(void *buf, s32 arg1);

extern "C" void func_001F9128(s32 *arg0) {
    s32 buf[4];

    func_001F90D8(buf);
    if (arg0 != buf) {
        s32 s0 = buf[0];
        if (s0 != 0) {
            func_002C0FE8(s0);
        }
        s32 temp_v0 = *arg0;
        if (temp_v0 != 0) {
            func_002C1050(temp_v0);
        }
        *arg0 = s0;
    }
    func_001F8C78(buf, 2);
}
