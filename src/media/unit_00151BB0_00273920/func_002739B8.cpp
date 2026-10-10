typedef int s32;

extern "C" void func_002738D0(void *buf);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_00273628(void *buf, s32 arg1);

extern "C" void func_002739B8(s32 *arg0) {
    s32 buf[4];

    func_002738D0(buf);
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
    func_00273628(buf, 2);
}
