typedef int s32;
typedef short s16;

struct S;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *, s32, s32);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern "C" s32 func_00206DD8(S *arg0);

extern "C" s32 func_0022F610(s32 arg0, void *arg1, void *arg2) {
    char *o = (char *)arg2;
    s32 r = 1;
    while (o != 0) {
        VEntry *e = (VEntry *)(((Obj *)o)->vtbl + 0x348);
        r = e->fn(o + e->delta, arg1, arg0, 1);
        if (r != 0) {
            break;
        }
        o = (char *)func_00206DD8((S *)o);
    }
    return r;
}
