typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

struct Obj {
    char pad0[4];
    char *vt;
};

struct VEntry {
    s16 delta;
    s16 index;
    void *(*fn)(void *, u8 *, u8 *);
};

extern "C" void func_001D35A0(void *arg0, void *arg1);
extern "C" void func_002ADC48(void *arg0, void *arg1);
extern "C" u8 *func_002AFE68(u8 *arg0);
extern "C" void func_0029EA18(void *arg0, void *arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_002ADBF0(void *arg0, int arg1);
extern "C" void func_001D3548(void *arg0, int arg1);

extern "C" void func_001D63A0(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s5;
    s32 *p_s4;
    s32 *p_s1;
    char *obj;
    VEntry *e;
    u8 *x1;
    u8 *r1;
    u8 *r2;
    void *t1;
    s32 newVal;
    s32 oldVal;
    if (arg2 >= 0x2) {
        func_001D35A0(buf0, arg1);
        p_s5 = buf1;
        func_002ADC48(p_s5, arg3);
        p_s4 = buf2;
        func_002ADC48(p_s4, (char *)arg3 + 0x4);
        x1 = (u8 *)p_s5[0];
        obj = (char *)buf0[0];
        e = (VEntry *)(((Obj *)obj)->vt + 0x328);
        obj = obj + e->delta;
        r1 = func_002AFE68(x1);
        r2 = func_002AFE68((u8 *)p_s4[0]);
        t1 = e->fn(obj, r1, r2);
        p_s1 = buf3;
        func_0029EA18(p_s1, t1);
        if (arg0 != p_s1) {
            newVal = *p_s1;
            if (newVal != 0) {
                func_002C0FE8((RefCounter *)newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050((RefCounter *)oldVal);
            }
            *arg0 = newVal;
        }
        func_0029CEF0(p_s1, 0x2);
        func_002ADBF0(p_s4, 0x2);
        func_002ADBF0(p_s5, 0x2);
        func_001D3548(buf0, 0x2);
    }
}
