/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
struct VE { s16 delta; s16 index; s32 (*fn)(void *); };
struct VO { char pad[4]; VE *vtbl; };
static inline s32 vcall(char *o) {
    VE *e = (VE *)((char *)((VO *)o)->vtbl + 0x68);
    return e->fn(o + e->delta);
}
extern "C" void *func_00234728(void *) throw();
extern "C" void func_002346D0(void *, s32) throw();
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
struct Obj { char pad[0xC8]; unsigned low:7; unsigned disk:1; unsigned high:24; };
extern "C" void func_00235148(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s0;
    s32 t1;
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        func_00234728(buf0);
        v_s0 = buf0[0];
        t1 = vcall((char *)*(s32 *)arg3);
        ((Obj *)v_s0)->disk = t1 != 0;
        func_002346D0(buf0, 2);
    } else {
        p_s1 = buf1;
        func_00234728(p_s1);
        func_0029EA18(buf0, ((Obj *)*p_s1)->disk);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) func_002C0FE8(newVal);
            oldVal = *arg0;
            if (oldVal != 0) func_002C1050(oldVal);
            *arg0 = newVal;
        }
        func_0029CEF0(buf0, 2);
        func_002346D0(p_s1, 2);
    }
}
