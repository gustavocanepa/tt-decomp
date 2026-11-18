/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct Holder {
    void *p;
    s32 n;
};

struct Obj {
    char *vtbl;
};

struct VE1 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VE5 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32, void *, s32, s32);
};

extern "C" void *func_004AE750(s32 a, s32 b);

extern "C" void func_00486D60(Holder *arg0, Obj *arg1)
{
    VE1 *e1;
    VE5 *e5;
    s32 n;
    void *b;

    arg0->p = 0;
    arg0->n = 0;
    e1 = (VE1 *)(arg1->vtbl + 0x10);
    n = e1->fn((char *)arg1 + e1->delta);
    b = func_004AE750(0x40, n);
    arg0->p = b;
    e5 = (VE5 *)(arg1->vtbl + 0x18);
    if (e5->fn((char *)arg1 + e5->delta, 0, b, n, 1) == 0) {
        u8 *a = (u8 *)arg0->p;
        u8 *q = a + 0x1FE;
        if (((q[1] << 8) | q[0]) == 0xAA55) {
            if ((a[0x1BE] & 0x7F) == 0) {
                arg0->n = 1;
            }
        }
    }
}
