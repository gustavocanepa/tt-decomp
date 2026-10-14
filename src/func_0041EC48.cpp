typedef int s32;
typedef short s16;
typedef float f32;

struct Ret_004596F8 {
    s32 w[4];
};

struct VEntryA_004596F8 {
    s16 delta;
    s16 index;
    void (*fn)(void *ret, void *self);
};

struct VEntryB_004596F8 {
    s16 delta;
    s16 index;
    void (*fn)(void *ret, void *self, f32 f);
};

struct Obj_004596F8 {
    void **vtbl;
};

extern "C" s32 func_0041E7F0(void *arg0, void *arg1);

extern "C" void func_0041EC48(void *arg0, void *arg1, f32 fparg0) {
    Ret_004596F8 sp0;
    Ret_004596F8 sp10;

    VEntryA_004596F8 *ea = (VEntryA_004596F8 *)((char *)((Obj_004596F8 *)arg1)->vtbl + 0x28);
    ea->fn(&sp0, (char *)arg1 + ea->delta);

    VEntryB_004596F8 *eb = (VEntryB_004596F8 *)((char *)((Obj_004596F8 *)arg0)->vtbl + 0x28);
    eb->fn(&sp10, (char *)arg0 + eb->delta, fparg0);

    func_0041E7F0(&sp10, &sp0);
}
