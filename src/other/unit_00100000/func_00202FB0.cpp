typedef int s32;
typedef float f32;

struct Dst {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

struct Src {
    char pad0[4];
};

struct VObj {
    char pad0[4];
    union {
        char *vtbl;
        s32 word;
    } u;
};

struct VEntryVal {
    short delta;
    short index;
    f32 (*fn)(void *);
};

extern "C" void func_00202788(void *arg0, int arg1);
extern "C" void func_002027E0(void *arg0, void *arg1);
extern "C" struct Dst *func_0020F950(struct Dst *arg0, struct Src *arg1);
extern "C" void func_0020FA30(struct Src *arg0, struct Dst *arg1);
extern "C" void func_002931C8(void *arg0, int arg1);
extern "C" void func_00293220(void *arg0, void *arg1);
extern "C" void func_002951D0(void *arg0, s32 arg1);
extern "C" s32 *func_00295260(void *arg0, s32 arg1);
extern "C" void func_00299AB0(void *arg0, int arg1);
extern "C" void func_0029B380(void *arg0, float fparg0);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

#define ASSIGN(dst, src)     if ((dst) != (src)) {         newVal = (src)[0];         if (newVal != 0) {             func_002C0FE8(newVal);         }         oldVal = *(dst);         if (oldVal != 0) {             func_002C1050(oldVal);         }         *(dst) = newVal;     }

static inline void init4(struct Dst *v, f32 x, f32 y, f32 z, f32 w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

static inline f32 vcall(struct VObj *q) {
    struct VEntryVal *e2 = (struct VEntryVal *)(q->u.vtbl + 0x70);
    return e2->fn((char *)q + e2->delta);
}

extern "C" void func_00202FB0(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    struct Src *h[4];
    union {
        struct Dst v;
        s32 arr1[4];
    } u;
    func_002027E0(h, arg1);
    if (arg2 == 0) {
        s32 arr[4];
        s32 buf[4];
        s32 *buf0;
        s32 *arr0;
        s32 *e;
        s32 newVal;
        s32 oldVal;
        func_0020F950(&u.v, h[0]);
        arr0 = arr;
        func_002951D0(arr0, 4);
        e = func_00295260(arr0, 0);
        buf0 = buf;
        func_0029B380(buf0, u.v.x);
        ASSIGN(e, buf0);
        func_00299AB0(buf0, 2);
        e = func_00295260(arr0, 1);
        func_0029B380(buf0, u.v.y);
        ASSIGN(e, buf0);
        func_00299AB0(buf0, 2);
        e = func_00295260(arr0, 2);
        func_0029B380(buf0, u.v.z);
        ASSIGN(e, buf0);
        func_00299AB0(buf0, 2);
        e = func_00295260(arr0, 3);
        func_0029B380(buf0, u.v.w);
        ASSIGN(e, buf0);
        func_00299AB0(buf0, 2);
        ASSIGN(arg0, arr0);
        func_002931C8(arr0, 2);
    } else if (arg2 == 1) {
        struct Dst vec;
        struct Dst *pvec;
        s32 *arr0;
        arr0 = u.arr1;
        func_00293220(arr0, arg3);
        pvec = &vec;
        init4(pvec, 0.0f, 0.0f, 0.0f, 0.0f);
        vec.x = vcall(*(struct VObj **)func_00295260(arr0, 0));
        vec.y = vcall(*(struct VObj **)func_00295260(arr0, 1));
        vec.z = vcall(*(struct VObj **)func_00295260(arr0, 2));
        vec.w = vcall(*(struct VObj **)func_00295260(arr0, 3));
        func_0020FA30(h[0], pvec);
        func_002931C8(arr0, 2);
    }
    func_00202788(h, 2);
}
