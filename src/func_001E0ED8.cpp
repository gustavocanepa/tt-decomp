typedef int s32;

extern "C" void func_001DF1F8(void *arg0, s32 arg1);
extern "C" void func_001DF250(void *arg0, void *arg1);
extern "C" s32 func_001E4558(s32 arg0);
extern "C" void func_001E45B0(void *arg0, s32 arg1);
extern "C" void func_001FBD88(void *arg0, void *arg1);
extern "C" void func_001FBDB8(void *arg0, s32 arg1);
extern "C" void func_001FBE10(void *arg0, void *arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void MRenderContext__get_transition(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p1;
    s32 *p2;
    s32 *p3;
    s32 newVal;
    s32 oldVal;
    s32 t1;
    if (arg2 == 0) {
        func_001DF250(buf0, arg1);
        p3 = buf3;
        t1 = func_001E4558(buf0[0]);
        p1 = buf1;
        buf3[0] = t1;
        func_001FBD88(p1, p3);
        if (arg0 != p1) {
            newVal = p1[0];
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_001FBDB8(p1, 2);
        func_001DF1F8(buf0, 2);
    } else {
        if (arg2 > 0) {
            func_001DF250(buf0, arg1);
            p2 = buf2;
            func_001FBE10(p2, arg3);
            func_001E45B0((void *)buf0[0], p2[0]);
            func_001FBDB8(p2, 2);
            func_001DF1F8(buf0, 2);
        }
    }
}
