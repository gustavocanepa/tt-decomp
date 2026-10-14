typedef int s32;
typedef unsigned char u8;

extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, s32 arg1);
extern "C" void func_002A2770(void *arg0, int arg1);
extern "C" void func_002A27C8(void *arg0, void *arg1);
extern "C" s32 func_002A4060(s32 arg0, s32 arg1);
extern "C" void func_002ADBF0(void *arg0, int arg1);
extern "C" void func_002ADC48(void *arg0, s32 arg1);
extern "C" s32 func_002AFE68(s32 arg0);
extern "C" void func_002C0FE8(s32 p);
extern "C" void func_002C1050(s32 p);

extern "C" void Module__load(s32 *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p0;
    s32 *p1;
    s32 sp0;
    s32 r;
    s32 newVal;
    s32 oldVal;

    r = 0;
    p0 = buf0;
    if (arg2 == 1) {
        func_002A27C8(p0, arg1);
        p1 = buf1;
        func_002ADC48(p1, arg3);
        sp0 = buf0[0];
        r = func_002A4060(sp0, func_002AFE68(p1[0]));
        func_002ADBF0(p1, 2);
        func_002A2770(p0, 2);
    }
    func_0029EA18(p0, r != 0);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_0029CEF0(p0, 2);
}
