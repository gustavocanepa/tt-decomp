typedef int s32;
typedef float f32;

struct VEntry {
    short delta;
    short index;
    f32 (*fn)(void *);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

struct Obj {
    char pad0[4];
};

extern "C" void func_001E9E40(void *arg0, int arg1);
extern "C" void func_001E9E98(void *arg0, void *arg1);
extern "C" f32 func_001EC160(Obj *arg0);
extern "C" void func_001EC168(Obj *arg0, f32 v);
extern "C" void func_00299AB0(void *arg0, int arg1);
extern "C" void func_0029B380(void *arg0, float fparg0);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_001EA3E0(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    Obj *h[4];
    if (arg2 == 0) {
        s32 buf[4];
        s32 *buf0;
        s32 newVal;
        s32 oldVal;
        f32 f;
        func_001E9E98(h, arg1);
        f = func_001EC160(h[0]);
        buf0 = buf;
        func_0029B380(buf0, f);
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
        func_001E9E40(h, 2);
    } else if (arg2 == 1) {
        func_001E9E98(h, arg1);
        {
            Obj *hv = h[0];
            VObj *o = *arg3;
            VEntry *e = (VEntry *)(o->vtbl + 0x70);
            func_001EC168(hv, e->fn((char *)o + e->delta));
        }
        func_001E9E40(h, 2);
    }
}
