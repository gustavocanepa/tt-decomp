/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

extern char D_005B17E8[];

struct VE2355E0 { s16 delta; s16 index; void *fn; };

extern "C" void func_001E80D0(void *, s32, float, float);
extern "C" void *func_001E94D8(void *);
extern "C" void func_0052A6B0(void *);

extern "C" void func_001E8E28(void *arg0) {
    s32 sp[4];
    char *vt;
    struct VE2355E0 *e;
    void *fn;
    func_0052A6B0((char *)arg0 + 0xF4);
    sp[0] = (s32)D_005B17E8;
    vt = *(char **)((char *)arg0 + 4);
    sp[1] = (s32)arg0;
    e = (struct VE2355E0 *)(vt + 0x1D8);
    fn = e->fn;
    ((void (*)(void *, void *))fn)((char *)arg0 + e->delta, sp);
    if (func_001E94D8(arg0) == 0) {
        func_001E80D0(arg0, 1, 0.0f, 0.0f);
    }
}
