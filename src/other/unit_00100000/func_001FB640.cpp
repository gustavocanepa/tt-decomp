typedef short s16;
typedef int s32;
typedef float f32;

struct VEntry {
    s16 delta;
    s16 pad;
    f32 (*fn)(void *);
};

struct ObjA {
    char pad0[4];
    VEntry *vtbl;
};

struct Arg3 {
    ObjA *obj;
};

extern "C" void func_001FB238(s32 *buf);
extern "C" void func_001FBC78(s32 arg0, f32 arg1);
extern "C" void func_001FB1E0(s32 *buf, s32 arg1);

extern "C" void func_001FB640(s32 arg0, s32 arg1, s32 arg2, Arg3 *arg3) {
    s32 buf[4];
    s32 s0;
    ObjA *obj;
    VEntry *entry;
    f32 result;

    if (arg2 == 1) {
        func_001FB238(buf);
        s0 = buf[0];
        obj = arg3->obj;
        entry = obj->vtbl + 14;
        result = entry->fn((char *)obj + entry->delta);
        func_001FBC78(s0, result);
        func_001FB1E0(buf, 2);
    }
}
