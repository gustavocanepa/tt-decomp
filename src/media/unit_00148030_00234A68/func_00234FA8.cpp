typedef int s32;
typedef short s16;
typedef float f32;

struct VEntry60 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct VEntry60V {
    s16 delta;
    s16 index;
    void (*fn)(void *, f32);
};

struct VObj60 {
    char pad0[4];
    char *vtbl;
};

static inline f32 vcall60(char *o) {
    VEntry60 *e = (VEntry60 *)(((VObj60 *)o)->vtbl + 0x70);
    return e->fn(o + e->delta);
}

static inline void vcall60v(char *o, f32 v) {
    VEntry60V *e = (VEntry60V *)(((VObj60 *)o)->vtbl + 0x60);
    e->fn(o + e->delta, v);
}

extern "C" void func_00234728(void *arg0, void *arg1);
extern "C" void func_002346D0(void *arg0, int arg1);

extern "C" void func_00234FA8(void *arg0, void *arg1, s32 arg2, void **arg3) {
    s32 buf0[4];
    f32 v = 0.0f;
    if (arg2 > 0) {
        v = vcall60((char *)*arg3);
    }
    func_00234728(buf0, arg1);
    char *obj = *(char **)((char *)buf0[0] + 0xB8);
    if (obj != 0) {
        vcall60v(obj, v);
    }
    *(f32 *)((char *)buf0[0] + 0xC4) = v;
    func_002346D0(buf0, 2);
}
