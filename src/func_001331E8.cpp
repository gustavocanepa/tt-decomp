typedef int s32;
typedef unsigned char u8;

extern "C" void func_00128470(void *arg0, void *arg1);
extern "C" void func_00128418(void *arg0, s32 arg1);
extern "C" void func_002951D0(void *arg0, s32 arg1);
extern "C" s32 *func_00295260(void *h, s32 arg);
extern "C" void func_0029EA18(void *arg0, s32 arg1);
extern "C" void func_0029CEF0(void *arg0, s32 arg1);
extern "C" void func_002931C8(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 p);
extern "C" void func_002C1050(s32 p);

extern "C" void MCarGarage__getBrakeControllerRange(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    u8 *s3;
    s32 *p_s2;
    s32 *s1;
    s32 newVal;
    s32 oldVal;

    func_00128470(buf0, arg1);
    s3 = (u8 *)buf0[0] + 0x30;
    func_00128418(buf0, 2);
    func_002951D0(buf0, 6);

    s1 = func_00295260(buf0, 0);
    p_s2 = buf1;
    func_0029EA18(p_s2, s3[3]);
    if (s1 != p_s2) {
        newVal = *p_s2;
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
    func_0029EA18(p_s2, s3[4]);
    if (s1 != p_s2) {
        newVal = *p_s2;
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
    func_0029EA18(p_s2, s3[5]);
    if (s1 != p_s2) {
        newVal = *p_s2;
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
    func_0029EA18(p_s2, s3[7]);
    if (s1 != p_s2) {
        newVal = *p_s2;
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

    s1 = func_00295260(buf0, 4);
    func_0029EA18(p_s2, s3[8]);
    if (s1 != p_s2) {
        newVal = *p_s2;
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

    s1 = func_00295260(buf0, 5);
    func_0029EA18(p_s2, s3[9]);
    if (s1 != p_s2) {
        newVal = *p_s2;
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
