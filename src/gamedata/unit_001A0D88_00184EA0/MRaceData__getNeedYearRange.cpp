typedef int s32;
typedef short s16;

struct RefCounter;

extern "C" void func_00184700(void *arg0, void *arg1);
extern "C" void func_002951D0(void *arg0, s32 arg1);
extern "C" s32 *func_00295260(void *h, s32 arg);
extern "C" void func_0029EA18(void *arg0, void *arg1);
extern "C" void func_0029CEF0(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);
extern "C" void func_002931C8(void *arg0, s32 arg1);
extern "C" void func_001846A8(void *arg0, s32 arg1);

extern "C" void MRaceData__getNeedYearRange(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    char *s5;
    s32 *p_s4;
    s32 *p_s2;
    s32 *s1;
    s32 newVal;
    s32 oldVal;

    func_00184700(buf0, arg1);
    p_s4 = buf1;
    s5 = (char *)buf0[0] + 0x10;
    func_002951D0(p_s4, 2);
    s1 = func_00295260(p_s4, 0);
    p_s2 = buf2;
    func_0029EA18(p_s2, (void *)(s32)*(s16 *)(s5 + 0x38));
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

    s1 = func_00295260(p_s4, 1);
    func_0029EA18(p_s2, (void *)(s32)*(s16 *)(s5 + 0x3A));
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

    if (arg0 != p_s4) {
        newVal = p_s4[0];
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_002931C8(p_s4, 2);
    func_001846A8(buf0, 2);
}
