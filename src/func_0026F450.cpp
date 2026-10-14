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

extern "C" void func_0026E9C0(s32 *buf, s32 arg);
extern "C" void func_0026E968(s32 *buf, s32 arg);
extern "C" void func_0026FD90(s32 obj, s32 flag);

extern "C" void func_0026F450(s32 unused, s32 arg1, s32 count, Arg3 *arg3) {
    s32 buf[4];
    s32 flag = 1;
    if (count > 0) {
        ObjA *obj = arg3->obj;
        VEntry *entry = obj->vtbl + 13;
        s32 result = entry->fn((char *)obj + entry->delta);
        flag = result != 0;
    }
    func_0026E9C0(buf, arg1);
    func_0026FD90(buf[0], flag);
    func_0026E968(buf, 2);
}
