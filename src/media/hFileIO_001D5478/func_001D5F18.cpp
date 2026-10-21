/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct RefCounter;

struct VEntry { s16 delta; s16 index; void *(*fn)(void *, s32, void *, void *); };
struct VObj { char pad0[4]; VEntry *vtbl; };

extern "C" void func_002ADC48(void *arg0, void *arg1) throw();
extern "C" void func_001D35A0(void *arg0, void *arg1) throw();
extern "C" u8 *func_002AFE68(u8 *arg0);
extern "C" s32 func_0029E9F0(void *arg0);
extern "C" void func_0029CF48(void *arg0, void *arg1);
extern "C" void func_0029EA18(void *arg0, void *arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_001D3548(void *arg0, int arg1) throw();
extern "C" void func_002ADBF0(void *arg0, int arg1);

extern "C" void func_001D5F18(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    if (arg2 >= 3) {
        s32 buf0[4];
        s32 buf1[4];
        s32 buf2[4];
        s32 buf3[4];
        s32 buf4[4];
        s32 *p_s7;
        s32 *p_s6;
        s32 *p_s5;
        s32 *p_s1;
        char *obj;
        VEntry *e;
        s32 r0;
        u8 *r1;
        u8 *r2;
        void *t1;
        s32 newVal;
        s32 oldVal;

        func_001D35A0(buf0, arg1);
        p_s7 = buf1;
        func_0029CF48(p_s7, arg3);
        p_s6 = buf2;
        func_002ADC48(p_s6, (char *)arg3 + 4);
        p_s5 = buf3;
        func_002ADC48(p_s5, (char *)arg3 + 8);
        obj = (char *)buf0[0];
        e = (VEntry *)((char *)((VObj *)obj)->vtbl + 0x310);
        obj = obj + e->delta;
        r0 = func_0029E9F0((void *)p_s7[0]);
        r1 = func_002AFE68((u8 *)p_s6[0]);
        r2 = func_002AFE68((u8 *)p_s5[0]);
        t1 = e->fn(obj, r0, r1, r2);
        p_s1 = buf4;
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
        func_0029CEF0(p_s1, 2);
        func_002ADBF0(p_s5, 2);
        func_002ADBF0(p_s6, 2);
        func_0029CEF0(p_s7, 2);
        func_001D3548(buf0, 2);
    }
}
