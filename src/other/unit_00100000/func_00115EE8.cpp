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

extern "C" void func_00115090(void *arg0, int arg1);
extern "C" void func_001150E8(void *arg0);
extern "C" s32 func_00117190(s32 arg0, s32 arg1);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_00115EE8(s32 *arg0, s32 arg1, s32 n, Obj **args) {
    s32 tmp[4];
    s32 buf0[4];
    s32 *pb;
    s32 newVal;
    s32 oldVal;
    s32 v;
    func_001150E8(tmp);
    v = 0;
    if (n > 0) {
        Obj *o = *args;
        VEntry *e = (VEntry *)(o->vtbl + 0x68);
        v = e->fn((char *)o + e->delta);
    }
    v = func_00117190(tmp[0], v);
    pb = buf0;
    func_0029EA18(pb, v);
    if (arg0 != pb) {
        newVal = *pb;
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_0029CEF0(pb, 2);
    func_00115090(tmp, 2);
}
