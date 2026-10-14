typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;
typedef long s64;
typedef float f32;

extern char D_005EED08[];
extern u32 D_00586A68[];

extern "C" void func_002ADC48(void *, void *);
extern "C" u8 *func_002AFE68(u8 *);
extern "C" s32 func_00455A48(u32 *, s32);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_002ADBF0(void *, s32);

extern "C" void MLocale__set(s32 *arg0, s32 arg1, void *arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    if (arg1 > 0) {
        func_002ADC48(buf0, arg2);
        void **pp = (void **)func_002AFE68((u8 *)buf0[0]);
        char *v1 = (char *)*pp;
        s32 len = *(s32 *)(v1 - 0x10);
        char *s;
        if (len == 0) {
            s = D_005EED08;
        } else {
            v1[len] = 0;
            s = (char *)*pp;
        }
        t1 = func_00455A48(D_00586A68, (s32)s);
        p_s1 = buf1;
        func_0029EA18(p_s1, t1);
        if (arg0 != p_s1) {
            newVal = *p_s1;
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_0029CEF0(p_s1, 0x2);
        func_002ADBF0(buf0, 0x2);
    }
}
