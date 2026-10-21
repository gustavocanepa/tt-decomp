typedef int s32;
typedef short s16;

struct VEntry_2C3A28 { s16 delta; s16 index; s32 (*fn)(void *); };
struct Obj_2C3A28 { s32 m0; VEntry_2C3A28 *vtbl; };

extern "C" void func_002655D8(void *arg0, void *arg1);
extern "C" void func_00265580(void *arg0, s32 arg1);

extern "C" void func_002660B8(void *a0, void *a1, s32 a2, Obj_2C3A28 **a3) {
    s32 buf[4];
    if (a2 > 0) {
        func_002655D8(buf, a1);
        Obj_2C3A28 *obj = *a3;
        char *p = (char *)buf[0] + 0x18;
        VEntry_2C3A28 *e = (VEntry_2C3A28 *)((char *)obj->vtbl + 0x68);
        s32 r = e->fn((char *)obj + e->delta);
        *(s32 *)(p + 0x8) = r;
        func_00265580(buf, 2);
    }
}
