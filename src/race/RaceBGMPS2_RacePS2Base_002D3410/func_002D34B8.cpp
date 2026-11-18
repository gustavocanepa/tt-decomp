/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry4A0 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *);
};

struct VEntry1A8 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32, void *);
};

struct Obj0 {
    char pad[0x64];
    char *vt4A0;
    char pad2[0x6C - 0x68];
    s32 f6C;
};

struct Obj1 {
    char pad[0x18];
    s32 f18;
    char pad1C[0x4848 - 0x1C];
    s32 f2888;
};

struct Obj2 {
    char *vt;
};

extern "C" s32 func_0030E928(s32 arg0);
extern "C" s32 func_002D34B8(void *arg0, struct Obj1 *arg1, struct Obj2 *arg2) {
    s32 result = 0;

    s32 mode = func_0030E928(arg1->f18);
    if (arg1->f2888 != 0) {
        if (mode >= 2) {
            {
                struct Obj0 *o = (struct Obj0 *)arg0;
                struct VEntry4A0 *e = (struct VEntry4A0 *)(o->vt4A0 + 0x4D8);
                if (e->fn((char *)o + e->delta, arg1) != 0) {
                    struct Obj2 *o2 = arg2;
                    struct VEntry1A8 *e2 = (struct VEntry1A8 *)(o2->vt + 0x1B8);
                    result = e2->fn((char *)o2 + e2->delta, o->f6C, arg1) != 0;
                }
            }
        }
    }
    return result;
}
