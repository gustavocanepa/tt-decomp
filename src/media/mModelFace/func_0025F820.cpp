/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
typedef float f32;

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct VObj {
    char pad0[4];
    union {
        char *vtbl;
        s32 word;
    } u;
};

struct Holder {
    struct VObj *p;
};

struct VEntryGet {
    short delta;
    short index;
    struct Holder *(*fn)(void *, s32);
};

struct VEntryVal {
    short delta;
    short index;
    f32 (*fn)(void *);
};

struct Obj {
    char pad0[4];
};

extern "C" void func_0025E6C0(void *arg0, int arg1) throw();
extern "C" void func_0025E718(void *arg0, void *arg1) throw();
extern "C" void func_002931C8(void *arg0, int arg1);
extern "C" void func_002951D0(void *arg0, s32 arg1);
extern "C" s32 *func_00295260(void *arg0, s32 arg1);
extern "C" void func_00299AB0(void *arg0, int arg1);
extern "C" void func_0029B380(void *arg0, float fparg0);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

#define ASSIGN(dst, src)     if ((dst) != (src)) {         newVal = (src)[0];         if (newVal != 0) {             func_002C0FE8(newVal);         }         oldVal = *(dst);         if (oldVal != 0) {             func_002C1050(oldVal);         }         *(dst) = newVal;     }

extern "C" void func_0025F820(s32 *arg0, void *arg1, s32 arg2, struct VObj **arg3) {
    struct Obj *h[4];
    s32 arr[4];
    s32 buf[4];
    struct Vec3 vec;
    if (arg2 == 0) {
        s32 *buf0;
        s32 *arr0;
        s32 *e;
        f32 *v;
        s32 newVal;
        s32 oldVal;
        func_0025E718(h, arg1);
        v = (f32 *)((u8 *)h[0] + 0x35C);
        arr0 = arr;
        func_002951D0(arr0, 3);
        e = func_00295260(arr0, 0);
        buf0 = buf;
        func_0029B380(buf0, v[0]);
        ASSIGN(e, buf0);
        func_00299AB0(buf0, 2);
        e = func_00295260(arr0, 1);
        func_0029B380(buf0, v[1]);
        ASSIGN(e, buf0);
        func_00299AB0(buf0, 2);
        e = func_00295260(arr0, 2);
        func_0029B380(buf0, v[2]);
        ASSIGN(e, buf0);
        func_00299AB0(buf0, 2);
        ASSIGN(arg0, arr0);
        func_002931C8(arr0, 2);
        func_0025E6C0(h, 2);
    } else if (arg2 == 1) {
        struct Vec3 *pv;
        f32 *py, *pz;
        func_0025E718(h, arg1);
        {
            struct VObj *o = *arg3;
            struct VEntryGet *e = (struct VEntryGet *)(o->u.vtbl + 0x78);
            struct VObj *q = e->fn((char *)o + e->delta, 0)->p;
            struct VEntryVal *e2 = (struct VEntryVal *)(q->u.vtbl + 0x70);
            f32 val = e2->fn((char *)q + e2->delta);
            pv = &vec;
            pv->x = val;
        }
        {
            struct VObj *o = *arg3;
            struct VEntryGet *e = (struct VEntryGet *)(o->u.vtbl + 0x78);
            struct VObj *q = e->fn((char *)o + e->delta, 1)->p;
            struct VEntryVal *e2 = (struct VEntryVal *)(q->u.vtbl + 0x70);
            f32 val = e2->fn((char *)q + e2->delta);
            py = &vec.y; *py = val;
        }
        {
            struct VObj *o = *arg3;
            struct VEntryGet *e = (struct VEntryGet *)(o->u.vtbl + 0x78);
            struct VObj *q = e->fn((char *)o + e->delta, 2)->p;
            struct VEntryVal *e2 = (struct VEntryVal *)(q->u.vtbl + 0x70);
            f32 val = e2->fn((char *)q + e2->delta);
            pz = &vec.z; *pz = val;
        }
        f32 *dst = (f32 *)((char *)h[0] + 0x35C);
        dst[0] = pv->x; dst[1] = *py; dst[2] = *pz;
        func_0025E6C0(h, 2);
    }
}
