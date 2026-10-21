typedef int s32;
typedef float f32;

extern "C" void func_001803E8(void *arg0, void *arg1);
extern "C" void func_001DF250(void *arg0, void *arg1);
extern "C" f32 func_00182E60(s32 arg0, s32 arg1);
extern "C" void func_001DF1F8(void *arg0, s32 arg1);
extern "C" void func_00180390(void *arg0, s32 arg1);
extern "C" void func_0029B380(void *arg0, f32 fparg0);
extern "C" void func_002C0FE8(s32 p);
extern "C" void func_002C1050(s32 p);
extern "C" void func_00299AB0(void *arg0, s32 arg1);

extern "C" void MPhotoRenderFace__getPrinterProgress(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 spare[4];
    s32 buf1[4];
    s32 *p0;
    s32 v_s2;
    s32 newVal;
    s32 oldVal;
    f32 fv;

    func_001803E8(buf0, arg1);
    p0 = buf1;
    v_s2 = buf0[0];
    func_001DF250(p0, arg3);
    fv = func_00182E60(v_s2, p0[0]);
    func_001DF1F8(p0, 2);
    func_00180390(buf0, 2);
    func_0029B380(buf0, fv);
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
    func_00299AB0(buf0, 2);
}
