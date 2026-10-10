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

extern "C" void func_0026E968(void *arg0, int arg1);
extern "C" void func_0026E9C0(void *arg0, void *arg1);
extern "C" f32 func_0026FEE0(s32 arg0);
extern "C" void func_0026FEE8(s32 arg0, f32 v);
extern "C" void func_00299AB0(void *arg0, int arg1);
extern "C" void func_0029B380(void *arg0, float fparg0);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_0026F2D0(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    s32 buf0[4];
    if (arg2 > 0) {
        f32 f;
        {
            VObj *o = *arg3;
            VEntry *e = (VEntry *)(o->vtbl + 0x70);
            f = e->fn((char *)o + e->delta);
        }
        func_0026E9C0(buf0, arg1);
        func_0026FEE8(buf0[0], f);
        func_0026E968(buf0, 2);
    } else {
        s32 buf1[4];
        s32 *p1 = buf1;
        s32 newVal;
        s32 oldVal;
        func_0026E9C0(p1, arg1);
        func_0029B380(buf0, func_0026FEE0(*p1));
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
        func_0026E968(p1, 2);
    }
}
