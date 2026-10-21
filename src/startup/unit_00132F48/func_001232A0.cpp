typedef int s32;
typedef short s16;

struct VEntry58 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VObj {
    s32 pad0;
    VEntry58 *vtbl;
};

static inline s32 vcall58(VObj *o) {
    VEntry58 *e = (VEntry58 *)((char *)o->vtbl + 0x68);
    return e->fn((char *)o + e->delta);
}

extern "C" s32 func_004AF530(s32, s32, s32);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_002A7578(void *, s32 *);
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

extern "C" void func_001232A0(s32 *ret, s32 argc, VObj **args) {
    s32 result[4];
    if (argc >= 3) {
        s32 day = func_004AF530(vcall58(args[0]), vcall58(args[1]), vcall58(args[2]));
        func_0029EA18(result, day);
        if (ret != result) {
            s32 newVal = result[0];
            if (newVal != 0)
                func_002C0FE8(newVal);
            s32 oldVal = *ret;
            if (oldVal != 0)
                func_002C1050(oldVal);
            *ret = newVal;
        }
        func_0029CEF0(result, 2);
    } else {
        s32 zero = 0;
        func_002A7578(result, &zero);
        if (ret != result) {
            s32 newVal = result[0];
            if (newVal != 0)
                func_002C0FE8(newVal);
            s32 oldVal = *ret;
            if (oldVal != 0)
                func_002C1050(oldVal);
            *ret = newVal;
        }
        func_002A75A8(result, 2);
    }
}
