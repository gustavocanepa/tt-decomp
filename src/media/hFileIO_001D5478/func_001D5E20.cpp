typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

struct VEntry_2E0 { s16 delta; s16 index; void *(*fn)(void *, void *); };
struct VObj_2E0 { char pad0[4]; VEntry_2E0 *vtbl; };

extern "C" void func_002ADC48(void *arg0, void *arg1);
extern "C" void func_001D35A0(void *arg0, void *arg1);
extern "C" u8 *func_002AFE68(u8 *arg0);
extern "C" void func_0029EA18(void *arg0, void *arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_001D3548(void *arg0, int arg1);
extern "C" void func_002ADBF0(void *arg0, int arg1);

extern "C" void func_001D5E20(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s3;
    s32 *p_s1;
    char *obj;
    VEntry_2E0 *e;
    void *t1;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        func_002ADC48(buf0, arg3);
        p_s3 = buf2;
        func_001D35A0(p_s3, arg1);
        obj = (char *)*p_s3;
        e = (VEntry_2E0 *)((char *)((VObj_2E0 *)obj)->vtbl + 0x308);
        obj = obj + e->delta;
        {
            u8 *r = func_002AFE68((u8 *)buf0[0]);
            t1 = e->fn(obj, r);
        }
        p_s1 = buf1;
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
        func_001D3548(p_s3, 0x2);
        func_002ADBF0(buf0, 0x2);
    }
}
