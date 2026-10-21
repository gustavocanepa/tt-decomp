typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

extern char D_005F7A40[];

struct Range {
    s32 v[4];
};

extern "C" Range func_00424178(s32 a, s32 b);
extern "C" void func_00423BB0(s32 a, s32 b);
extern "C" void func_004241E8(s32 *arg0, void *arg1);

struct VEntryPTCL {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VEntryPTCL3 {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, void *);
};

struct NodePTCL {
    NodePTCL *next;
    struct {
        char pad[0];
    } dummy;
    char *vtbl;
};

extern "C" void func_00393838(void *arg0, s32 arg1) {
    Range r = func_00424178(arg1, (s32)D_005F7A40);
    char *self = (char *)arg0;
    char *n;
    s32 v;

    func_00423BB0(arg1, 0);
    n = *(char **)(self + 4);
    if (n != 0) {
        do {
            VEntryPTCL *e8 = (VEntryPTCL *)(*(char **)(n + 4) + 0x8);
            v = e8->fn(n + e8->delta);
            func_00423BB0(arg1, v + 1);
            VEntryPTCL3 *e28 = (VEntryPTCL3 *)(*(char **)(n + 4) + 0x28);
            e28->fn(n + e28->delta, arg1, arg0);
            n = *(char **)n;
        } while (n != 0);
    }
    func_00423BB0(arg1, 0);
    func_004241E8(r.v, (void *)arg1);
}
