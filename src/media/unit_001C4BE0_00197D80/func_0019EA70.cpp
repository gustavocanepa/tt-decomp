/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct VE1CF578 {
    short delta;
    short index;
    void *fn;
};

extern char D_005AC7A0[];
extern "C" int func_0019E8E8(void *arg0, void *arg1);

extern "C" s32 func_0019EA70(s32 arg0, s32 arg1, s32 arg2) {
    char *vt = D_005AC7A0;
    char obj[0x10];
    f32 one = 1.0f;
    *(s32 *)(obj + 4) = arg2;
    *(char **)obj = vt;
    VE1CF578 *e1 = (VE1CF578 *)(vt + 0x10);
    ((void (*)(void *, s32, f32))e1->fn)(obj + e1->delta, arg1, 0.0f);
    VE1CF578 *e2 = (VE1CF578 *)(*(char **)obj + 0x10);
    ((void (*)(void *, f32))e2->fn)(obj + e2->delta, one);
    s32 r = func_0019E8E8((void *)arg0, (void *)arg1);
    VE1CF578 *e3 = (VE1CF578 *)(*(char **)obj + 0x10);
    ((void (*)(void *, f32))e3->fn)(obj + e3->delta, one);
    return r == 0;
}
