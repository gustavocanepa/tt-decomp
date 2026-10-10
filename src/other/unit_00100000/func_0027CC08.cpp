typedef int s32;

extern "C" void func_0013BDC0(s32 *arg0, s32 arg1);
extern "C" void func_0027BEF0(s32 *arg0, s32 arg1);
extern "C" void func_001E6480(s32 *arg0, s32 arg1);
extern "C" void func_0027E268(s32 arg0, s32 arg1);
extern "C" void func_0013BD68(s32 *arg0, s32 arg1);
extern "C" void func_0027BE98(s32 *arg0, s32 arg1);
extern "C" void func_001E6428(s32 *arg0, s32 arg1);

extern "C" void func_0027CC08(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf0[8];
    s32 buf1[4];

    if (arg2 > 0) {
        func_0027BEF0(buf0, arg1);
        s32 val0 = buf0[0];
        s32 *p1 = buf1;
        func_001E6480(p1, arg3);
        func_0027E268(val0, p1[0]);
        func_001E6428(p1, 2);
        func_0027BE98(buf0, 2);
    }
}
