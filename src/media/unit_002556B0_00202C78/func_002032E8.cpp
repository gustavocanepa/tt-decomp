typedef int s32;

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern "C" void func_00202788(void *arg0, int arg1);
extern "C" void func_002027E0(void *arg0, void *arg1);
extern "C" s32 func_0020D610(s32 arg0);
extern "C" void func_0020D620(s32 arg0, s32 arg1);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_002032E8(s32 *arg0, void *arg1, s32 arg2, Obj **arg3) {
    s32 buf0[4];
    if (arg2 == 0) {
        s32 buf1[4];
        s32 *p1 = buf1;
        s32 newVal;
        s32 oldVal;

        func_002027E0(p1, arg1);
        func_0029EA18(buf0, func_0020D610(*p1) != 0);
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
        func_0029CEF0(buf0, 2);
        func_00202788(p1, 2);
    } else if (arg2 == 1) {
        Obj *o = *arg3;
        VEntry *e = (VEntry *)(o->vtbl + 0x68);
        s32 flag = e->fn((char *)o + e->delta) != 0;
        func_002027E0(buf0, arg1);
        func_0020D620(buf0[0], flag);
        func_00202788(buf0, 2);
    }
}
