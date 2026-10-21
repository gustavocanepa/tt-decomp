typedef int s32;
typedef long s64;
typedef unsigned char u8;

extern "C" s32 func_00128470(void *arg0, void *arg1);
extern "C" void func_00128418(void *arg0, s32 arg1);
extern "C" void func_002951D0(void *arg0, s32 arg1);
extern "C" s32 func_001324D8(void *arg0);
extern "C" s64 func_00408288(void *arg0);
extern "C" s32 *func_00295260(void *h, s32 arg);
extern "C" void func_0029EA18(void *arg0, s32 arg1);
extern "C" void func_0029CEF0(void *arg0, s32 arg1);
extern "C" void func_002931C8(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 p);
extern "C" void func_002C1050(s32 p);

extern "C" void func_001347D8(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 *s1;
    u8 *s3;
    s64 s0;
    u8 s5 = 0;
    u8 s6 = 0;
    s32 newVal;
    s32 oldVal;

    func_00128470(buf0, arg1);
    s3 = (u8 *)buf0[0] + 0x30;
    func_00128418(buf0, 2);
    func_002951D0(buf0, 4);
    p_s2 = buf1;
    func_00128470(p_s2, arg1);
    s0 = func_00408288((void *)func_001324D8((void *)p_s2[0]));
    func_00128418(p_s2, 2);
    if (s0 != -1) {
        s5 = s3[0x13F];
        s6 = s3[0x140];
    }

    s1 = func_00295260(buf0, 0);
    func_0029EA18(p_s2, s3[0x61] + s5);
    if (s1 != p_s2) {
        newVal = p_s2[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    s1 = func_00295260(buf0, 1);
    func_0029EA18(p_s2, s3[0x62] + s6);
    if (s1 != p_s2) {
        newVal = p_s2[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    s1 = func_00295260(buf0, 2);
    func_0029EA18(p_s2, s3[0x64] + s5);
    if (s1 != p_s2) {
        newVal = p_s2[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    s1 = func_00295260(buf0, 3);
    func_0029EA18(p_s2, s3[0x65] + s6);
    if (s1 != p_s2) {
        newVal = p_s2[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

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
    func_002931C8(buf0, 2);
}
