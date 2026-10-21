typedef int s32;

extern "C" void func_002BC270(s32 *arg0);
extern "C" s32 func_002BB3A8(s32 arg0);
extern "C" void func_002A6108(s32 arg0, s32 *arg1, s32 arg2);
extern "C" void func_002BC150(s32 arg0);
extern "C" void func_002BC0E0(s32 *arg0, s32 arg1);

extern "C" void func_002B96F8(s32 arg0, s32 arg1) {
    s32 buf[4];
    s32 temp_v0;

    func_002BC270(buf);
    temp_v0 = func_002BB3A8(arg1);
    func_002A6108(temp_v0, buf, arg0 + 8);
    if (buf[0] != 0) {
        func_002BC150(buf[0]);
    }
    func_002BC0E0(buf, 2);
}
