typedef int s32;

extern "C" void func_00279388(void *buf);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_00279078(void *buf, s32 arg1);

extern "C" void func_002793D8(s32 *arg0) {
    s32 buf[4];

    func_00279388(buf);
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
    func_00279078(buf, 2);
}
