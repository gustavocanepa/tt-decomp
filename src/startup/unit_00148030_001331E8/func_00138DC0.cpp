typedef int s32;
typedef unsigned int u32;

struct RefCounter;

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

extern "C" void func_00128470(void *arg0, void *arg1);
extern "C" void func_00128418(void *arg0, int arg1);
extern "C" s32 func_001324D8(s32 arg0);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, u32 arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);
extern "C" void func_002E4610(u32 *arg0, u32 arg1);

extern "C" void func_00138DC0(s32 *arg0, void *arg1, s32 n, Obj **args) {
    s32 buf[4];
    s32 newVal;
    s32 oldVal;
    u32 *s2;

    func_00128470(buf, arg1);
    s2 = (u32 *)((char *)func_001324D8(buf[0]) + 0x4E8);
    func_00128418(buf, 2);
    if (n > 0) {
        Obj *o = args[0];
        VEntry *e = (VEntry *)(o->vtbl + 0x68);
        s32 v = e->fn((char *)o + e->delta);
        func_002E4610(s2, v);
        return;
    }
    func_0029EA18(buf, *s2);
    if (arg0 != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_0029CEF0(buf, 2);
}
