typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 pad;
    s32 (*fn)(void *);
};

struct ObjA {
    char pad0[4];
    VEntry *vtbl;
};

struct Arg3 {
    ObjA *obj;
};

extern "C" void func_001BE1C0(s32 *buf);
extern "C" void func_001BEC80(s32 arg0, s32 arg1);
extern "C" void func_001BE168(void *buf, s32 arg1);

extern "C" void func_001BE818(s32 arg0, s32 arg1, s32 n, Arg3 *arg3) {
    if (n > 0) {
        s32 buf[4];
        s32 r;
        func_001BE1C0(buf);
        {
            ObjA *o = arg3->obj;
            VEntry *e = o->vtbl + 13;
            r = e->fn((char *)o + e->delta);
        }
        func_001BEC80(buf[0], r != 0);
        func_001BE168(buf, 2);
    }
}
