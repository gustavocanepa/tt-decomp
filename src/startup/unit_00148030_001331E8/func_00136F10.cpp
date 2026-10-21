typedef int s32;
typedef unsigned char u8;

struct RefCounter;

extern "C" void func_00128470(void *arg0, void *arg1);
extern "C" void func_00128418(void *arg0, s32 arg1);
extern "C" void func_002951D0(void *arg0, s32 arg1);
extern "C" s32 *func_00295260(void *h, s32 arg);
extern "C" void func_0029EA18(void *arg0, void *arg1);
extern "C" void func_0029CEF0(void *arg0, s32 arg1);
extern "C" void func_002931C8(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);

extern "C" void func_00136F10(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 *s1;
    u8 *s3;
    s32 newVal;
    s32 oldVal;

    func_00128470(buf0, arg1);
    s3 = (u8 *)buf0[0] + 0x30;
    func_00128418(buf0, 2);
    func_002951D0(buf0, 0xC);
    s1 = func_00295260(buf0, 0);
    p_s2 = buf1;
    func_0029EA18(p_s2, (void *)(s32)s3[0x126]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    s1 = func_00295260(buf0, 1);
    func_0029EA18(p_s2, (void *)(s32)s3[0x127]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    s1 = func_00295260(buf0, 2);
    func_0029EA18(p_s2, (void *)(s32)s3[0x128]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    s1 = func_00295260(buf0, 3);
    func_0029EA18(p_s2, (void *)(s32)s3[0x12C]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    s1 = func_00295260(buf0, 4);
    func_0029EA18(p_s2, (void *)(s32)s3[0x12D]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    s1 = func_00295260(buf0, 5);
    func_0029EA18(p_s2, (void *)(s32)s3[0x12E]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    s1 = func_00295260(buf0, 6);
    func_0029EA18(p_s2, (void *)(s32)s3[0x131]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    s1 = func_00295260(buf0, 7);
    func_0029EA18(p_s2, (void *)(s32)s3[0x132]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    s1 = func_00295260(buf0, 8);
    func_0029EA18(p_s2, (void *)(s32)s3[0x133]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    s1 = func_00295260(buf0, 9);
    func_0029EA18(p_s2, (void *)(s32)s3[0x137]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    s1 = func_00295260(buf0, 0xA);
    func_0029EA18(p_s2, (void *)(s32)s3[0x138]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    s1 = func_00295260(buf0, 0xB);
    func_0029EA18(p_s2, (void *)(s32)s3[0x139]);
    if (s1 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *s1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    func_0029CEF0(p_s2, 2);

    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_002931C8(buf0, 2);
}
