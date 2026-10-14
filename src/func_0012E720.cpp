typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct ObjA {
    char pad0[4];
    VEntry *vtbl;
};

extern "C" void func_00128418(void *arg0, int arg1);
extern "C" void func_00128470(void *arg0, void *arg1);
extern "C" s32 func_001324D8(s32 arg0);
extern "C" void func_00408800(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_0012E720(s32 *arg0, void *arg1, s32 arg2, ObjA **arg3) {
    s32 buf[4];
    s32 v;
    if (arg2 > 0) {
        func_00128470(buf, arg1);
        {
            ObjA *o = *arg3;
            VEntry *e = o->vtbl + 13;
            v = e->fn((char *)o + e->delta);
        }
        func_00408800(func_001324D8(buf[0]), v & 0xFFFF, 0);
        func_00128418(buf, 2);
    }
}
